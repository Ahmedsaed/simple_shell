OUT_FILE := shell
BUILD_DIR := build
SRC_DIR := .
INCLUDE_DIR := include
TEST_DIR := tests
TMP_DIR := .tmp

CC := gcc
CFlags := -Wall -Werror -Wextra -pedantic -std=gnu89

SOURCE_FILES = $(wildcard *.c)
HEADER_FILES = $(wildcard *.h)
INTEGRATION_TESTS_FILES = $(patsubst $(TEST_DIR)/integration/%.i,%,$(wildcard $(TEST_DIR)/integration/*.i))
UNIT_TEST_FILES = $(notdir $(wildcard $(TEST_DIR)/unit/*.c))

all: clear_screen check_style build run_tests check_memory

build: setup_dirs 
	@printf -- "\n---- Compiling program ----\n"
	@${CC} ${CFlags} ${SOURCE_FILES} -o ./$(BUILD_DIR)/${OUT_FILE}.out

integration_tests: $(INTEGRATION_TESTS_FILES)

$(INTEGRATION_TESTS_FILES): %: $(TEST_DIR)/%.i $(TEST_DIR)/%.o 
	@./$(BUILD_DIR)/$(OUT_FILE).out < $< | diff -c $(word 2, $?) - >${TMP_DIR}/$@.diff && \
	(echo "test $@ succeeded" && exit 0) || \
	(echo "test $@ failed" && cat ${TMP_DIR}/$@.diff && exit 1)

unit_tests:
	@for file in $(UNIT_TEST_FILES); do \
		$(CC) $$file $(TEST_DIR)/unit/$$file -o $(TMP_DIR)/tmp.o; \
		if ./$(TMP_DIR)/tmp.o 2>&1 >/dev/null; then \
			echo "Test $$file succedded"; \
		else \
			echo "Test $$file failed"; \
			./$(TMP_DIR)/tmp.o; \
		fi; \
		rm -f ./$(TMP_DIR)/tmp.o; \
	done

run_tests: setup_dirs integration_tests
	@echo "Success, all tests passed."

clean:
	rm ./${BUILD_DIR}/*.out
	rm -rf ./${TMP_DIR}

setup_dirs:
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TMP_DIR)

check_style:
	@printf -- "---- Checking Code Style ----\n"
	@betty ${SOURCE_FILES} ${HEADER_FILES}

check_memory:
	@printf -- "\n---- Checking memory leaks ----\n"
	@for file in $(INTEGRATION_TESTS_FILES); do \
		(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 \
		./${BUILD_DIR}/${OUT_FILE}.out < $(TEST_DIR)/$$file.i >>${TMP_DIR}/$$file.vg 2>&1)  && \
		(echo "No memory leaks in integration_tests $$file" && exit 0) || \
		(echo "Error: memory leak in integration_tests $$file" && cat ${TMP_DIR}/$$file.vg && exit 1) \
	done

clear_screen:
	clear

OUT_FILE := shell
BUILD_DIR := build
SRC_DIR := .
INCLUDE_DIR := include
TEST_DIR := tests
TMP_DIR := .tmp
MAKEFLAGS += -s

CC := gcc
CFlags := -Wall -Werror -Wextra -pedantic -std=gnu89 -ggdb3

SOURCE_FILES = $(wildcard *.c)
HEADER_FILES = $(wildcard *.h)
INTEGRATION_TESTS_FILES = $(patsubst $(TEST_DIR)/integration/%.py,%,$(wildcard $(TEST_DIR)/integration/*.py))
UNIT_TEST_FILES = $(patsubst %.c, %, $(notdir $(wildcard $(TEST_DIR)/unit/*.c)))

all: clear_screen check_style build run_tests check_memory

build: setup_dirs
	@${CC} ${CFlags} ${SOURCE_FILES} -o ./$(BUILD_DIR)/${OUT_FILE}.out
	@$(MAKE) announce MESSAGE="Compiled successfully"
run:
	@./$(BUILD_DIR)/$(OUT_FILE).out

integration_tests: $(INTEGRATION_TESTS_FILES)

$(INTEGRATION_TESTS_FILES): %: $(TEST_DIR)/integration/%.py
	@python $< 

unit_tests:
	@for file in $(UNIT_TEST_FILES); do \
		$(CC) $(filter-out shell.c, $(SOURCE_FILES)) $(TEST_DIR)/unit/$$file.c -o $(TMP_DIR)/tmp.o; \
		if ./$(TMP_DIR)/tmp.o 2>&1 >/dev/null; then \
			echo "Test $$file succedded"; \
		else \
			echo "Test $$file failed"; \
		fi; \
		./$(TMP_DIR)/tmp.o; \
		rm -f ./$(TMP_DIR)/tmp.o; \
	done

run_tests: setup_dirs 
	@$(MAKE) announce MESSAGE="Running unit tests"
	@$(MAKE) -k unit_tests
	@$(MAKE) announce MESSAGE="Running integration tests"
	@$(MAKE) -k integration_tests

clean:
	rm ./${BUILD_DIR}/*.out
	rm -rf ./${TMP_DIR}

announce:
	@echo "------------------------------------------"
	@printf "|%*s%s%*s|\n" $$(expr 20 - $${#MESSAGE} / 2) "" "$(MESSAGE)" $$(expr 20 - $$(($${#MESSAGE} + 1)) / 2) ""
	@echo "------------------------------------------"

setup_dirs:
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TMP_DIR)

check_style:
	@$(MAKE) announce MESSAGE="Checking code style"
	@betty-style --no-summary ${SOURCE_FILES} ${HEADER_FILES}
	@betty-doc ${SOURCE_FILES} ${HEADER_FILES} > $(TMP_DIR)/betty-doc.txt && \
		(make announce MESSAGE="No styling issuse found" && exit 0) || \
		(cat $(TMP_DIR)/betty-doc.txt && exit 1)

check_memory:
	@$(MAKE) announce MESSAGE="Checking memory leaks"
	(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 \
	./${BUILD_DIR}/${OUT_FILE}.out < $(TEST_DIR)/sample_input.txt >>${TMP_DIR}/$$file.vg 2>&1)  && \
	(make announce MESSAGE="No memory leaks found" && exit 0) || \
	(echo "Error: memory leak found" && cat ${TMP_DIR}/$$file.vg && exit 1) \

clear_screen:
	clear

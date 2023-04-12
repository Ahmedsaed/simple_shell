application := hsh
build_dir := build
src_dir := .
include_dir := include

CC := gcc
CFlags := -Wall -Werror -Wextra -pedantic -std=gnu89

SOURCE_FILES = ./tests/main.c $(wildcard *.c)
HEADER_FILES = $(wildcard *.h)

all: clear_screen check_style build check_memory run

build: setup_dirs 
	${CC} ${CFlags} ${SOURCE_FILES} -o ./$(build_dir)/${application}.out

run:
	./${build_dir}/${application}.out

clean:
	rm ./${build_dir}/*.out

setup_dirs:
	@mkdir -p ./build

check_style:
	betty ${SOURCE_FILES} ${HEADER_FILES}

check_memory:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${build_dir}/${application}.out

clear_screen:
	clear

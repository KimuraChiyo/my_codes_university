CC=gcc
FLAGS=-Wall -Werror -Wextra -W -std=c11

ifeq ($(shell uname -s), Linux)
	TEST_COMMAND = bash
else
	TEST_COMMAND = sh 
endif

all: check-format s21_grep

formatting: 
	clang-format --style=Google -i *.c *.h
	clang-format --style=Google -i ../grep/*.c ../grep/*.h

check-format:
	clang-format --style=Google -n *.c *.h

s21_grep:
	$(CC) $(FLAGS) s21_grep.c s21_grep_functions.c -o s21_grep

miniverter: formatting
	$(TEST_COMMAND) ../../materials/build/run.sh 

test: all
	$(TEST_COMMAND) s21_grep_testing.sh
	rm s21_grep

rebuild: clean all

clean: 
	rm s21_grep
CC = gcc
DEBUGGER = gdb
CFLAGS = -Wall -Werror -Wextra 
GET_OBJECTS = -Wall -Werror -Wextra -std=c11 -c
ALL_SOURCE = functions/*.c
ALL_TESTS_SOURCE = tests/*.c
ALL_OBJECTS = *.o
LIBS = -lcheck $(shell pkg-config --cflags --libs check) -lm 

GOAL = s21_matrix.a

all: $(GOAL)

$(GOAL):
	$(CC) $(GET_OBJECTS) $(ALL_SOURCE)
	ar r $(GOAL) $(ALL_OBJECTS)

build_test: $(GOAL)
	$(CC) $(CFLAGS) $(ALL_TESTS_SOURCE) $(GOAL) $(LIBS) -o test

test: $(GOAL) build_test
	./test

valgrind: clean build_test
	valgrind --leak-check=full --show-leak-kinds=all ./test

gcov_report: $(GOAL)
	gcc -lcheck --coverage $(ALL_SOURCE) $(ALL_TESTS_SOURCE) $(LIBS) -o test
	./test
	gcovr --exclude-throw-branches -d --html-details tests.html
	firefox tests.html

debug: $(GOAL)
	$(CC) $(ALL_SOURCE) $(ALL_TESTS_SOURCE) $(LIBS) -g -o debug
	$(DEBUGGER) ./debug

style:
	clang-format -i --style=Google functions/* tests/* *.h
	cppcheck functions/* tests/* --check-level=exhaustive

clean:
	rm -rf *.o 
	rm -rf *.gcda
	rm -rf  *.gcno
	rm -rf  *.a
	rm -rf  *.gcna
	rm -rf  *.gch
	rm -rf  test
	rm -rf  *.css
	rm -rf  *.html
	rm -rf  test
	rm -rf  debug

rebuild: clean test
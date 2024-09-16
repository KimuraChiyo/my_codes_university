CC = gcc
CFLAGS = -Wall -Werror -Wextra
GET_OBJECTS = -Wall -Werror -Wextra -std=c11 -c
ALL_SOURCE = function_files/*.c
ALL_OBJECTS = *.o
LIBS = -lcheck $(shell pkg-config --cflags --libs check) -lm 

all: s21_decimal.a

s21_decimal.a:
	$(CC) $(GET_OBJECTS) $(ALL_SOURCE)
	ar r s21_decimal.a $(ALL_OBJECTS)

test: s21_decimal.a
	$(CC) $(CFLAGS) tests/* s21_decimal.a $(LIBS) -o test
	./test

timeit_test: s21_decimal.a
	$(CC) $(CFLAGS) tests/* s21_decimal.a $(LIBS) -o test
	timeit ./test

#gcovr -d удаляет gcda сразу после отчета
gcov_report: s21_decimal.a
	gcc --coverage  $(ALL_SOURCE) tests/* $(LIBS) -o test
	./test
	gcovr -d --html tests.html

gcov_details: s21_decimal.a
	gcc -lcheck --coverage $(ALL_SOURCE) tests/* $(LIBS) -o test
	./test
	gcovr -d --html-details tests.html

debug: s21_decimal.a
	gcc $(ALL_SOURCE) tests/*.c $(LIBS) -g -o debug
	gdb ./debug

style:
	clang-format -i --style=Google function_files/* tests/* *.h

valgrind: test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -rf *.o *.gcda *.gcno *.a *.gcna *.gch test *.css *.html test debug

rebuild: clean test
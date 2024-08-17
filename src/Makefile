CC = gcc -std=c11 -Wall -Wextra -Werror
OS = $(shell uname)

ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	FLAGS = -lcheck
endif

all: quadratic_equation.a

quadratic_equation.a:
	$(CC) -c quadratic_equation.c
	ar -rc quadratic_equation.a quadratic_equation.o
	ranlib quadratic_equation.a
	rm -f *.o

check: clean quadratic_equation.a test_quadratic_equation.o
	$(CC) test_quadratic_equation.o quadratic_equation.a $(FLAGS) -o test
	./test

test_quadratic_equation.o:
	$(CC) -c ./tests/test_quadratic_equation.c -o test_quadratic_equation.o

clang:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h

clean:
	rm -f test quadratic_equation.a *.o

valgrind: check
	CK_FORK=no valgrind  --leak-check=full  --track-origins=yes  ./test
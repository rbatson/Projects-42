CC_FLAGS=-Wall -Werror -Wextra -std=c11

OS=$(shell uname -s)
ifeq ($(OS),Linux)
	TEST_FLAGS=-lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	CC_FLAGS+=-lm
else
	TEST_FLAGS=-lcheck
endif

all: clean s21_math.a

rebuild: clean all

test: s21_math.o atest.o
	gcc $(CC_FLAGS) -o do_test.out atest.o s21_math.o $(TEST_FLAGS)
	./do_test.out

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

gcov_report: clean testing.sh s21_math.c
	bash testing.sh
	gcc $(CC_FLAGS) --coverage -o make_report.out atest.c s21_math.c $(TEST_FLAGS)
	./make_report.out
	lcov -t "make_report" -o make_report.info -c -d . 
	genhtml -o report make_report.info

atest.o: testing.sh
	bash testing.sh
	gcc -c $(CC_FLAGS) atest.c

s21_math.o: s21_math.c
	gcc -c $(CC_FLAGS) s21_math.c

style: clean
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h

leaks: test
	CK_FORK=no leaks --atExit -- ./do_test.out

clean:
	rm -rf *.o *.gch *.out *.gcno *.gcda *.info *.gcov
	rm -rf report/
	rm -rf temp/
	rm -rf atest.c

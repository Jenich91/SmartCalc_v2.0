.PHONY: all clean tests gcov_report
SHELL := /bin/bash

PROJECT_NAME = smartcalc
INSTALL_PATH=../Build
CC = g++
EXTRAWARN_FLAGS = -Wpedantic -Wshadow -Wuninitialized 
WARN_FLAGS= -Wall -Werror -Wextra
CFLAGS = -std=c++17 -lstdc++ $(WARN_FLAGS)
DEBUG_FLAG = -g
GCOVFLAG = --coverage
LDFLAGS = -lgtest
TEST_SRCS = tests.cc
SRCS = model.cc controller.cc view.cc model.h controller.h view.h
VERSION = v2.0
FILENAME = s21_$(PROJECT_NAME)_$(VERSION)
OS := $(shell uname)

ifeq ($(OS), Linux)
LDFLAGS += -lgtest_main -lpthread
LCOV=$(shell which lcov)
GENHTML=$(shell which genhtml)
endif

ifeq ($(OS),Darwin)
BREW := ${HOME}/homebrew/brew/bin/brew
ifeq ($(shell test -e $(BREW) && echo -n yes),yes)
LCOV=$(shell which lcov)
GENHTML=$(shell which genhtml)
else
LCOV=/opt/goinfre/$(USER)/brew/bin/lcov
GENHTML=/opt/goinfre/$(USER)/brew/bin/genhtml
endif
endif

all: install
	
tests: clean
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LDFLAGS) model.cc -o tests.out
	./tests.out

install: clean
	qmake $(PROJECT_NAME).pro -o Qmakefile
	make -f Qmakefile install INSTALL_ROOT=$(INSTALL_PATH)
	rm -rf $(FILENAME).app
	make  dvi
	open $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/$(FILENAME)

dist: install dvi
	tar -cvzf $(FILENAME)_$(VERSION).tar.gz $(INSTALL_PATH)/$(FILENAME)
	cp $(FILENAME)_$(VERSION).tar.gz $(INSTALL_PATH)
	rm $(FILENAME)_$(VERSION).tar.gz
	open $(INSTALL_PATH)

dvi:
	makeinfo --html --no-split -o README.html $(PROJECT_NAME).texi --force
	mkdir -p $(INSTALL_PATH)/$(FILENAME)/
	cp README.html $(INSTALL_PATH)/$(FILENAME)/
	rm README.html

clean:
	qmake $(PROJECT_NAME).pro -o Qmakefile
	make -f Qmakefile clean
	rm -rf *.o *.a *.gcno test ./report ./*.dSYM test.info *.out *.gcda gcov_report *.info .clang-format *.user .qmake.stash
	rm -R -f ../.DS_Store .DS_Store *.dSYM
	rm -rf .DS_Store DS_Store *.tmp

gcov_report: clean
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LDFLAGS) model.cc $(GCOVFLAG) -o tests.out
	./tests.out
	ls tests.out
	$(LCOV) -t tests.out -o tests.info -c -d . --no-external
	$(GENHTML) tests.info -o report
	open report/index.html
	
style_check: clang-format cppcheck linter

linter:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py $(SRCS)
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --language=c++ --std=c++17 --suppress=unusedFunction --suppress=missingInclude --suppress=unknownMacro --suppress=unmatchedSuppression $(SRCS)

clang-format:
	cp -a ../materials/linters/.clang-format .clang-format
	clang-format -i *.cc
	clang-format -n *.cc
	rm -rf .clang-format

leaks: debug
ifeq ($(OS), Darwin)
	leaks --atExit -- ./debug.out -exclude
else
	valgrind -q --tool=memcheck --leak-check=full --leak-resolution=med ./debug.out
endif

debug: clean
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LIB_NAME) -I./ -L./ $(LDFLAGS)  model.cc -o debug.out -ggdb3
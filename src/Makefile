MAIN_PROJ_NAME=my_containers_oop
TEST_C=*.h $(MAIN_PROJ_NAME)_test.cc
EXECUTABLE=$(MAIN_PROJ_NAME)_test.out
COMPILER=g++
STD=-std=c++17
TEST_FLAGS=-lgtest -pthread
CLANG_FILE=.clang-format
CLANG_FILE_WAY=../materials/linters/$(CLANG_FILE)
CHECK_FILES=*.cc include/*.h
CPPCH_SETUP=--enable=warning,performance,portability -v --language=c++ -$(STD)
TO_DELETE=*.o *.out *.dSYM *.gch .DS_Store $(EXECUTABLE) $(CLANG_FILE)
VALGRIND_SETUP=--tool=memcheck --leak-check=full --show-leak-kinds=all

all: check test

check:
	cppcheck $(CPPCH_SETUP) $(CHECK_FILES)
	cp $(CLANG_FILE_WAY) $(CLANG_FILE)
	clang-format -n --style=Google $(CHECK_FILES)

clean:
	rm -rf $(TO_DELETE)

test: clean
	$(COMPILER) $(STD) -o $(EXECUTABLE) $(MAIN_PROJ_NAME)_test.cc $(TEST_FLAGS) -I include
	./$(MAIN_PROJ_NAME)_test.out

valgrind: clean
	$(COMPILER) -g $(STD) -o $(EXECUTABLE) $(MAIN_PROJ_NAME)_test.cc $(TEST_FLAGS) -I include
	CK_FORK=no valgrind $(VALGRIND_SETUP) ./$(EXECUTABLE)

leaks: test
	CK_FORK=no leaks -atExit -- ./$(EXECUTABLE)

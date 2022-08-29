CXX = clang++
CXXFLAG = -Wall -Wextra -Werror -std=c++98

all:
	@echo "USAGE: make <container>"

list:
	@$(CXX) $(CXXFLAG) test/listTest.cpp -o a.out
	@./a.out
	@rm a.out

vector:
	@$(CXX) $(CXXFLAG) test/vectorTest.cpp -o a.out
	@./a.out
	@rm a.out

map:
	@$(CXX) $(CXXFLAG) test/mapTest.cpp -o a.out
	@./a.out
	@rm a.out

stack:
	@$(CXX) $(CXXFLAG) test/stackTest.cpp -o a.out
	@./a.out
	@rm a.out

queue:
	@$(CXX) $(CXXFLAG) test/queueTest.cpp -o a.out
	@./a.out
	@rm a.out
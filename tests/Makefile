#SRCS := $(wildcard ../src/*.cc *.cc ../src/*.h *.h)
    
search:
	g++ -std=c++20 -O3 -pthread -Wall -Werror -pedantic -g ../src/SearchEngine.cc ../src/SearchEngine.h *.cc *.h -o test
valgrind:
	g++ -std=c++20 -g -O3 -pthread -Wall -Werror -pedantic -g ../src/SearchEngine.cc ../src/SearchEngine.h *.cc *.h -o debug

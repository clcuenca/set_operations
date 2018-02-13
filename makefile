CPPFLAGS =-Wall -g -pedantic -pedantic-errors -std=c++11

set_operations_test.o: set_operations_test.cpp setoperations.hpp
	g++ $(CPPFLAGS) -c set_operations_test.cpp

set_operations_test: set_operations_test.o
	g++ $(CPPFLAGS) -o set_operations_test set_operations_test.o
	rm set_operations_test.o

clean:
	rm -f set_operations_test set_operations_test.o

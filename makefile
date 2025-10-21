test: test_bst_example.o
	g++ -o test test_bst_example.o
	
sorting_test.o: test_bst_example.cpp BTS.h BTS.cpp
	g++ -c test_bst_example.cpp
clean:
	rm -f test *.o
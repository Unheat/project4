all: test
test: test_bst_example.o
	g++ -o test test_bst_example.o
test_bst_example.o: test_bst_example.cpp BST.h BST.cpp
	g++ -c test_bst_example.cpp
usecase: usecase.cpp BST.h
	g++ -o usecase usecase.cpp
clean:
	rm -f test usecase *.o


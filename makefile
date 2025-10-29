all: test #default run make
test: bst_test.o
	g++ -o test bst_test.o
bst_test.o: bst_test.cpp BST.h BST.cpp
	g++ -c bst_test.cpp
usecase: usecase.cpp BST.h
	g++ -o usecase usecase.cpp
clean:
	rm -f test usecase *.o


#include "BST.h"
#include <fstream>  
#include <string>  
#include <stdexcept> 
#include <sstream>
#include <iostream>
using namespace std;
template <typename D, typename K>
BST<D,K>* create_bst(string fname){
    std::ifstream inputFile(fname);
    if(!inputFile.is_open()){
        throw runtime_error("file not found");
    }
    BST<D, K>* bst = new BST<D,K>();
    std::string line;
    while (getline(inputFile, line)) { // Reads a line into 'line' until end of file or error
       stringstream ss(line); 
       string hex_data, bin_key;
       if(getline(ss, hex_data, ',')&& getline(ss, bin_key)){
            bst->insert(hex_data, bin_key);
       }
    }
    inputFile.close();
    return bst;
}
template <typename D, typename K>
string convert(BST<D,K>* bst, string bin){
    // Pad the front of the input with additional zeros if not a multiple of 4.
    while (bin.length() % 4 != 0)
    {
        bin = "0" + bin;
    }
    std::string hex_result = "";
    for(int i = 0; i <bin.length(); i+= 4){
        std::string part = bin.substr(i,4);
        hex_result += bst->get(part);
    }
    return hex_result;
}

void test(){
    BST<string,string>* test = new BST<string,string>();
    test = create_bst<string,string>("binhex.txt");
    std::string input;
    std::cout << "Enter binary representation for conversion:" << std::endl;
    std::cin >> input;
    std::string hexResult = convert(test, input);
    std::cout << "Hexadecimal representation of " << input << " is " << hexResult << std::endl;
}
int main(){
    test();
}
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

void testUserInput(){
    BST<string,string>* test = new BST<string,string>();
    test = create_bst<string,string>("binhex.txt");
    std::string input;
    std::cout << "Enter binary representation for conversion:" << std::endl;
    std::cin >> input;
    std::string hexResult = convert(test, input);
    std::cout << "Hexadecimal representation of " << input << " is " << hexResult << std::endl;
}
void test_binhex()
{
    try
    {
        BST<string, string> *bst1 = create_bst<string, string>("binhex.txt");
        string bin1 = "111010100101";
        string expected_hex1 = "EA5";

        string hex1 = convert<string, string>(bst1, bin1);
        delete bst1;

        if (hex1 != expected_hex1)
        {
            cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try
    {
        BST<string, string> *bst2 = create_bst<string, string>("binhex.txt");
        string bin2 = "110101";
        string expected_hex2 = "35";

        string hex2 = convert<string, string>(bst2, bin2);
        delete bst2;

        if (hex2 != expected_hex2)
        {
            cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
        try
    {
        BST<string, string> *bst3 = create_bst<string, string>("binhex.txt");
        string bin3 = "";
        string expected_hex3 = "";

        string hex3 = convert<string, string>(bst3, bin3);
        delete bst3;

        if (hex3 != expected_hex3)
        {
            cout << "Incorrect result converting " << bin3 << " to hex. Expected : " << expected_hex3 << ", but got : " << hex3 << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
}
int main(){
    test_binhex();
    testUserInput();
}
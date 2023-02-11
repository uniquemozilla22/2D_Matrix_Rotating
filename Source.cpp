#include <iostream>  
using namespace std;
#include "MRotator.h" 
#include <fstream>

int main() {
    MRotator key;
    ifstream file_in("input.txt");
    ofstream file_out("output.txt");

    if (file_in.is_open() &&
        file_out.is_open()) {
        while (!file_in.eof()) {
            file_in >> key;
            key.rotate();
            file_out << key;
        }
    }
    return 0;
}
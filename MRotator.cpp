





#include "MRotator.h"
#include <fstream>
#include <string>;
#include <iostream>;
#include <vector>
using namespace std;

std::ifstream& operator>>(std::ifstream& inputFile, MRotator& key)
{
	if (inputFile.eof()) {
		exit(0);
	}
	std::string line;
	std::getline(inputFile, line);

    string str = line;
    vector<int> ar;
    for (int i = 0; i < str.length()  ; i++) {
        if (str[i] != ',' && str[i] != ' ') {
            // Append the char to the temp string.
            string s(1, str[i]);
            ar.push_back(stoi(s));
        }
    }

    key.r_size = ar.at(0);//2
    key.c_size = ar.at(1);//3


    int row = ar.at(0);
    int col = ar.at(1);

    int squared_side_number;

    if (row > col) {
        squared_side_number = row;
        key.addedCounter = row - col;
    }
    else {
        squared_side_number = col;
        key.addedCounter = col - row;
    }

    key.sided_number_matrix = squared_side_number;
   
    int** matrix = new int* [squared_side_number];
    int** rotated_matrix = new int* [squared_side_number];


    for (int i = 0; i < squared_side_number; i++)
    {
        matrix[i] = new int[squared_side_number];
        rotated_matrix[i] = new int[squared_side_number];
    }

    for (int i = 0; i < squared_side_number; i++)
    {
        for (int j = 0; j < squared_side_number; j++) {
            matrix[i][j] = 0;
            rotated_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {
            int element = rand() % 10;
            matrix[i][j] = element;
            rotated_matrix[i][j] = element;
        }
    }
    
    key.matrix = matrix;
    key.rotated__matrix = rotated_matrix;
	return inputFile;
}
std::ostream& operator<<(std::ostream& outputFile, MRotator& Rotator)
{

    outputFile << "Generated matrix: " << "[" << Rotator.r_size << "," << Rotator.c_size << "]" << std::endl;


    for (int i = 0; i < Rotator.r_size; i++) {
        cout << i;
        for (int j = 0; j < Rotator.c_size; j++) {
            cout << " " << j;
            outputFile << Rotator.matrix[i][j] << " ";
        }
        cout << "data" << endl;
        outputFile << endl;
    }

    outputFile << endl;

    outputFile << "Rotated Output: " << endl;


    for (int i = 0; i < Rotator.sided_number_matrix; i++) {
        for (int j = 0; j < Rotator.sided_number_matrix; j++) {
            outputFile << Rotator.rotated__matrix[i][j] << " ";
        }
        outputFile << endl;
    }


    outputFile << "Resize counter: " << Rotator.addedCounter << std::endl;
    outputFile << "---------------------------------------------------------------------"<<endl<<endl;
    return outputFile;
};


string removeSpaces(string inputword)
{
	inputword.erase(std::remove(inputword.begin(), inputword.end(), ' '), inputword.end());
	return inputword;
}

void MRotator::rotate()
{
    int N = sided_number_matrix;
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = rotated__matrix[i][j];
            rotated__matrix[i][j] = rotated__matrix[N - 1 - j][i];
            rotated__matrix[N - 1 - j][i] = rotated__matrix[N - 1 - i][N - 1 - j];
            rotated__matrix[N - 1 - i][N - 1 - j] = rotated__matrix[j][N - 1 - i];
            rotated__matrix[j][N - 1 - i] = temp;
        }
    }
}

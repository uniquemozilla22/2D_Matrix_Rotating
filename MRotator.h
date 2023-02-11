#ifndef STRINGEDITOR_H_
#define STRINGEDITOR_H_
#include <string>
#include <fstream>

/// <summary>
/// Class that takes the data from the file creates a 2d array and rotates it making it a sqaure dimensions. 
/// </summary>
class MRotator
{

private:

	int r_size, c_size; // contains the dimension of the 2d array
	int** matrix; // the 2d array without the zero generated 
	int** rotated__matrix; // the 2d array that contains the address of the rotated matrix
	int sided_number_matrix; // the value of the size of the square side
	int addedCounter; // how many added columns or rows are in the matrix

public:

	/// <summary>
	/// Method that rotates the matrix and stores it into rotated__matrix
	/// </summary>
	void rotate();
	/// <summary>
	/// Friend operator overloading to get the file contents and create a 2d Array
	/// </summary>
	/// <param name="inputFile"> File for reading the texts</param>
	/// <param name="key"> Rotater Class </param>
	/// <returns>File after reading </returns>
	friend std::ifstream& operator>> (std::ifstream& inputFile, MRotator& key);

	/// <summary>
	/// Friend operter overloading to print the desired output from the file
	/// </summary>
	/// <param name="os"> Output file that the output will be printed on</param>
	/// <param name="mr"> Rotater class</param>
	/// <returns>Output file </returns>
	friend std::ostream& operator<<(std::ostream& os, MRotator& mr);
};


#endif

//20191339 ChanhwiHwang
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string myIntegerToBinary(int n) {
	if (n <= 1) return to_string(n);  // Base case(termination condition) - Could not be divided by 2
	return myIntegerToBinary(n / 2) + to_string(n % 2);  // Recursive case - Add remainder at the end of the next call's return value and return it
}

int main() {
	fstream inFile, outFile;  // Define file streams
	inFile.open("Program1Input.txt", ios::in);
	outFile.open("Program1Output.txt", ios::out);
	
	int num;
	inFile >> num;  // Read an integer from input file stream
	inFile.close();
	
	outFile << myIntegerToBinary(num) << '\n';  // Write the result of Integer to Binary conversion to output file stream
	outFile.close();
	
	return 0;
}

//20191339 ChanhwiHwang
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool is_number(string str) {  // Determine whether str is real-valued number
	int dotCount = 0;  // number of dot in str
	for (int i = 0; i < str.length(); i++) {
		if (str.length() == 1)  // When the length of string is 1, it should be 0-9 number
			if (isdigit(str[0])) return true;
			else return false;
		if (i == 0)
			if (str[0] == '-' || str[0] == '+') continue;  // Sign at the front is OK
		if (!isdigit(str[i]) && str[i] != '.') return false;  // Special Characters are not allowed
		if (str[i] == '.') {  // When the character is dot
		    // Check whether the position of dot is correct and its front and back character is digit
			if (i == 0 || i == str.length() - 1) return false;
			if (!isdigit(str[i - 1])) return false;
			dotCount++;
		}
		if (dotCount >= 2) return false;  // number of dot should be 0 or 1
	}
	return true;
}

fstream inFile1, inFile2, outFile;  // Filestreams
void exitWithError(int errorType) {  // Function to handle the exceptions
	outFile << "Error#" << errorType << '\n';
	outFile.close();
	inFile1.close();
	inFile2.close();
}

int main() {
	inFile1.open("Program2InputA.txt", ios::in);
	inFile2.open("Program2InputB.txt", ios::in);
	outFile.open("Program2Output20191339.txt", ios::out);
	
	if (inFile1.fail() || inFile2.fail()) {  // Any of two input files not exist -> error case #0
		outFile << "Error#0" << '\n';
		outFile.close();
		if (!inFile1.fail()) inFile1.close();  // Since it is not sure that both input files are opened, check whether it is open and if so, close it
		if (!inFile2.fail()) inFile2.close();
		return -1;
	}
	
	int rowA, colA, rowB, colB;  // The number of rows and columns of each matrix
	inFile1 >> rowA >> colA;
	inFile2 >> rowB >> colB;
	if (colA != rowB) {  // If the number of column of A and the number of row of B are not equal -> matrix product does not defined -> error case #2
		exitWithError(2);
		return -1;
	}
	
	double matrixA[rowA][colA];  // 2-dimensional arrays to store matrix entries
	double matrixB[rowB][colB];
	string temp;  // Temporary variable to use as argument to is_number to check each input value is number
	
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < colA; j++) {
			int curIndex = inFile1.tellg();  // Store current cursur location
			inFile1 >> temp;
			if (!is_number(temp)) {  // Check whether current input is number
				exitWithError(1);  // If it is non-number -> error case #1
				return -1;
			}
			// Move back to the stored location and read the input value as number
			inFile1.clear();
			inFile1.seekg(curIndex);
			inFile1 >> matrixA[i][j];
		}
	}
	inFile1.close();
	
	// Same processes as above
	for (int i = 0; i < rowB; i++) {
		for (int j = 0; j < colB; j++) {
			int curIndex = inFile2.tellg();
			inFile2 >> temp;
			if (!is_number(temp)) {
				exitWithError(1);
				return -1;
			}
			inFile2.clear();
			inFile2.seekg(curIndex);
			inFile2 >> matrixB[i][j];
		}
	}
	inFile2.close();
	
	outFile << rowA << ' ' << colB << '\n';  // Write the rows and columns of output matrix
	
	outFile << setprecision(6);  // Set the precision to 6 digits after the decimal point(by rounding off)
	outFile << fixed;
	
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < colB; j++) {
			double sum = 0;
			for (int k = 0; k < colA; k++) {
				sum += matrixA[i][k] * matrixB[k][j];  // Calculate the each entry of output matrix by finding inner product of i-th row of matrixA and j-th column of matrixB
			}
			outFile << sum << (j == colB - 1 ? '\n' : ' ');  // Write the calculated entry and seperator character, if it reaches the end of each column, insert '\n' to move to new line, otherwise, insert whitespace
		}
	}
	outFile.close();
	return 0; 
}

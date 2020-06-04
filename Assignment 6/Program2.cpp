#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool is_number(string str) {
	int dotCount = 0;
	for (int i = 0; i < str.size(); i++) {
		if (i == 0 && str[0] == '-') continue;
		if (!isdigit(str[i]) && str[i] != '.') return false;
		if (str[i] == '.') {
			if (i == 0 || i == str.size() - 1) return false;
			if (!isdigit(str[i - 1])) return false;
			dotCount++;
		}
		if (dotCount >= 2) return false;
	}
	return true;
}

fstream inFile1, inFile2, outFile;
void exitWithError(int errorType) {
	outFile << "Error#" << errorType << '\n';
	outFile.close();
	if (inFile1.is_open()) inFile1.close();
	if (inFile2.is_open()) inFile2.close();
}

int main() {
	inFile1.open("Program2InputA.txt", ios::in);
	inFile2.open("Program2InputB.txt", ios::in);
	outFile.open("Program2Output20191339.txt", ios::out);
	
	if (inFile1.fail() || inFile2.fail()) {
		exitWithError(0);
		return -1;
	}
	
	int rowA, colA, rowB, colB;
	inFile1 >> rowA >> colA;
	inFile2 >> rowB >> colB;
	if (colA != rowB) {
		exitWithError(2);
		return -1;
	}
	
	double matrixA[rowA][colA];
	double matrixB[rowB][colB];
	string temp;
	
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < colA; j++) {
			int curIndex = inFile1.tellg();
			inFile1 >> temp;
			if (!is_number(temp)) {
				exitWithError(1);
				return -1;
			}
			inFile1.seekg(curIndex);
			inFile1 >> matrixA[i][j];
		}
	}
	inFile1.close();
	
	for (int i = 0; i < rowB; i++) {
		for (int j = 0; j < colB; j++) {
			int curIndex = inFile2.tellg();
			inFile2 >> temp;
			if (!is_number(temp)) {
				exitWithError(1);
				return -1;
			}
			inFile2.seekg(curIndex);
			inFile2 >> matrixB[i][j];
		}
	}
	inFile2.close();
	
	outFile << setprecision(6);
	outFile << fixed;
	
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < colB; j++) {
			double sum = 0;
			for (int k = 0; k < colA; k++) {
				sum += matrixA[i][k] * matrixB[k][j];
			}
			outFile << sum << (j == colB - 1 ? '\n' : ' ');
		}
	} 
	outFile.close();
	return 0; 
}

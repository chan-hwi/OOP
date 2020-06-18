//20191339 ChanhwiHwang
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mySwap(double& num1, double& num2) {  // mySwap function to swap two double variables
	double temp = num2;
	num2 = num1;
	num1 = temp;
}
void mySwap(string& str1, string& str2) {  // mySwap function to swap two string variables
	string temp = str2;
	str2 = str1;
	str1 = temp;
}

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

int main() {
	fstream inFile, outFile;
	inFile.open("Program1Input.txt", ios::in);
	outFile.open("Program1Output20191339.txt", ios::out);
	if (inFile.fail()) {  // When input file does not exist -> error case #0
		outFile << "Error#0" << '\n';
		outFile.close();
		return -1;
	}
	
	int count = 0;  // A variable to store the number of inputs and refer to current index
	// Define arrays to store inputs as itself(temp) and as numbers(nums)
	string temp[50];
	double nums[50];
	
	while (!inFile.eof()) {  // Check if the current input is number
		int curIndex = inFile.tellg();  // Store current cursor location
		inFile >> temp[count];
		if (!is_number(temp[count])) {  // There's non-number string -> error case #1
			outFile << "Error#1" << '\n';
			inFile.close();
			outFile.close();
			return -1;
		}
		if (temp[count][0] == '+') {  // If it has + sign, eliminate the sign character since +a = a, a is real number 
			string str;
			for (int i = 1; i < temp[count].length(); i++) str += temp[count][i];
			temp[count] = str;
		}
		// Move to stored location to read current input again as number, not string
		inFile.clear();
		inFile.seekg(curIndex, ios::beg);
		inFile >> nums[count++];  // Update the number of inputs
	}
	inFile.close();
	
	//sorting - Selection Sort : repeatedly find smallest element and locate it at the front of current iteration's array(indices with i ~ end)
	// => In i-th loop, i-th element becomes smallest among i ~ end elements -> compare i-th element with rest of elements and if i-th element is larger, swap them to keep i-th element
	// be the smallest element 
	for (int i = 0; i < count - 1; i ++) {
		for (int j = i + 1; j < count; j++) {
			if (nums[i] > nums[j]) {
				mySwap(nums[i], nums[j]);
				mySwap(temp[i], temp[j]);
			}
		}
	}
	
	for (int i = 0; i < count; i++) {
		outFile << temp[i] << (i == count-1 ? "" : " ");  // Print sorted numbers seperated with whitespace to output file
	}
	
	outFile.close();
	return 0;
}

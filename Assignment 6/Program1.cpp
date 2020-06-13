#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mySwap(double& num1, double& num2) {
	double temp = num2;
	num2 = num1;
	num1 = temp;
}
//void mySwap(string& str1, string& str2) {
//	string temp = str2;
//	str2 = str1;
//	str1 = temp;
//}

bool is_number(string str) {
	int dotCount = 0;
	for (int i = 0; i < str.size(); i++) {
		if (i == 0)
			if (str[0] == '-' || str[0] == '+') continue;
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

int main() {
	fstream inFile, outFile;
	inFile.open("Program1Input.txt", ios::in);
	outFile.open("Program1Output20191339.txt", ios::out);
	if (inFile.fail()) {
		outFile << "Error#0" << '\n';
		outFile.close();
		return -1;
	}
	int index = 0, count = 0;
//	string temp[50];
	string temp;
	double nums[50];
	
	int curIndex = inFile.tellg();
//	inFile >> temp[index];
	inFile >> temp;
	while (!inFile.eof()) {
//		if (!is_number(temp[index])) {
		if (!is_number(temp)) {
			outFile << "Error#1" << '\n';
			inFile.close();
			outFile.close();
			return -1;
		}
		inFile.clear();
		inFile.seekg(curIndex, ios::beg);
		inFile >> nums[index++];
		count++;
		curIndex = inFile.tellg();
//		inFile >> temp[index];
		inFile >> temp;
	}
	inFile.close();
	
	//sorting
	for (int i = 0; i < count - 1; i ++) {
		for (int j = i + 1; j < count; j++) {
			if (nums[i] > nums[j]) {
				mySwap(nums[i], nums[j]);
//				mySwap(temp[i], temp[j]);
			}
		}
	}
	
	for (int i = 0; i < count; i++) {
//		outFile << temp[i] << (i == count-1 ? "" : " ");
		outFile << nums[i] << (i == count-1 ? "" : " ");
	}
	
	outFile.close();
	return 0;
}

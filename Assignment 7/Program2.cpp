#include <iostream>
#include <fstream>
using namespace std;

int reverse(int Input, int result = 0) {
	return (Input ? reverse(Input / 10, result * 10 + Input % 10) : result);
}

int reverseandadd(int Input)
{
	int Output;
	// Your code here . . .
	Output = Input + reverse(Input);
	return Output;
}


int main() {
	fstream inFile, outFile;
	inFile.open("Program2Input.txt", ios::in);
	outFile.open("Program2Output.txt", ios::out);
	
	int num, count = 0;
	inFile >> num;
	inFile.close();
	bool isPossible = false;
	while (count < 1000) {
		if (num == reverse(num)) {
			isPossible = true;
			break;
		}
		num = reverseandadd(num);
		count++;
	}
	outFile << num << ' ' << count;
	
	outFile.close();
}

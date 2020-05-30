#include <iostream>
#include <fstream>
using namespace std;

int DP[29];  // Define an array to store the return values of function to avoid repetitive calling with same argument

int myFibonacci(int n) {
	// Two base cases, 0-th term of fibonacci : 0, 1th term : 1
	if (n == 0) return 0;  
	if (n == 1) return 1;
	if (DP[n - 2]) return DP[n - 2];  // In the case of n > 1, check if the result of calling with n exists in DP[n - 2] and if so, return the value
	
	// If it's not exists in DP, call the recursive case and store the result to corresponding index of DP.
	DP[n - 2] = myFibonacci(n - 1) + myFibonacci(n - 2);  // Recursive case - call itself with n - 1 and n - 2 cases and return the sum of them
	return DP[n - 2];
}

int main() {
	fstream inFile, outFile;  // Define file streams and open them
	inFile.open("Program2Input.txt", ios::in);
	outFile.open("Program2Output.txt", ios::out);
	
	int num;
	inFile >> num;  // Read an integer from input file stream
	outFile << myFibonacci(num) << '\n';  // Write the return value of the function to output file stream
	inFile.close();
	outFile.close();
	
	return 0;
}

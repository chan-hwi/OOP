//20191339 ChanhwiHwang
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream inFile, outFile;
	inFile.open("Input.txt", ios::in);  // Open each file stream with read(in) and write(out) mode.
	outFile.open("Output.txt", ios::out);
	
	outFile << fixed;  // To show decimal up to 6 below floating point at each output
	outFile << setprecision(6);
	
	string temp;  // string buffer to get the input value from "inFile" input file stream
	inFile >> temp;  // reading the number of cases
	int N = atoi(temp.c_str());  // Conversion from string to integer type
	for (int i = 1; i <= N; i++) {  // i represents the index of each case
		int NumOfScore, sum = 0;
		inFile >> temp;  // reading the number of students
		NumOfScore = atoi(temp.c_str());
		int scores[NumOfScore];  // an array to store the scores of each student to compare it later with the average of them
		for (int j = 0; j < NumOfScore; j++) {
			inFile >> temp;  // reading the each student's score
			int curScore = atoi(temp.c_str());
			sum += scores[j] = curScore;
		}
		double avg = (double)sum / NumOfScore;
		int HighThanAvg = 0;
		for (int j = 0; j < NumOfScore; j++) {  //repeatedly comparing with average
			if (scores[j] < avg) HighThanAvg++;
		}
		outFile << '#' << i << ' ' << HighThanAvg / (double)NumOfScore * 100 << '%' << '\n';
	}
	
	inFile.close();  // closing file streams
	outFile.close();
	
}

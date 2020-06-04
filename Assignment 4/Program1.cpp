//20191339 ChanhwiHwang
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	fstream inFile, outFile;
	inFile.open("Input.txt", ios::in);  // Open each file stream with read(in) and write(out) mode.
	outFile.open("Output.txt", ios::out);
	
	outFile << fixed;  // To show decimal up to 6 below floating point at each output
	outFile << setprecision(6);
	
	int N;
	inFile >> N;  // reading the number of cases
	for (int i = 1; i <= N; i++) {  // i represents the index of each case
		int NumOfScore, sum = 0;
		inFile >> NumOfScore;
		int scores[NumOfScore];  // an array to store the scores of each student to compare it later with the average of them
		for (int j = 0; j < NumOfScore; j++) {
			int curScore;
			inFile >> curScore;  // reading the each student's score
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

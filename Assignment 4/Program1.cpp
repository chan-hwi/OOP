#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream inFile, outFile;
	inFile.open("Input.txt", ios::in);
	outFile.open("Output.txt", ios::out);
	
	outFile << fixed;
	outFile << setprecision(6);
	
	string temp;
	inFile >> temp;
	int N = atoi(temp.c_str());
	for (int i = 1; i <= N; i++) {
		int NumOfScore, sum = 0;
		inFile >> temp;
		NumOfScore = atoi(temp.c_str());
		int scores[NumOfScore];
		for (int j = 0; j < NumOfScore; j++) {
			inFile >> temp;
			int curScore = atoi(temp.c_str());
			sum += scores[j] = curScore;
		}
		double avg = (double)sum / NumOfScore;
		int HighThanAvg = 0;
		for (int j = 0; j < NumOfScore; j++) {
			if (scores[j] < avg) HighThanAvg++;
		}
		outFile << '#' << i << ' ' << HighThanAvg / (double)NumOfScore * 100 << '%' << '\n';
	}
	
	inFile.close();
	outFile.close();
	
}

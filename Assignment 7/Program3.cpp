#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double matrix[20][20];
double inverse[20][20];

void rowExchange(int row1, int row2, int N) {
	double temp;
	for (int k = 0; k < N; k++) {
		temp = matrix[row1][k];
		matrix[row1][k] = matrix[row2][k];
		matrix[row2][k] = temp;
		temp = inverse[row1][k];
		inverse[row1][k] = inverse[row2][k];
		inverse[row2][k] = temp;
	}
}

int main() {
	fstream inFile, outFile;
	inFile.open("Program3Input.txt", ios::in);
	outFile.open("Program3Output.txt", ios::out);
	
	int N;
	inFile >> N >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			inFile >> matrix[i][j];
			inverse[i][j] = (i == j ? 1 : 0);
		}
	}
	
	for (int j = 0; j < N; j++) {
		if (matrix[j][j] == 0) {
			int changable = j;
			for (int m = j + 1; m < N; m++) {
				if (matrix[m][j]) {
					changable = m;
					break;
				}
			}
			rowExchange(j, changable, N);
		}
		for (int i = j + 1; i < N; i++) {
			double c = matrix[i][j] / matrix[j][j];
			for (int k = 0; k < N; k++) {
				matrix[i][k] -= c * matrix[j][k];
				inverse[i][k] -= c * inverse[j][k];
			}
		}
	}
	
	for (int j = N - 1; j > 0; j--) {
		for (int i = j - 1; i >= 0 ; i--) {
			double c = matrix[i][j] / matrix[j][j];
			for (int k = 0; k < N; k++) {
				matrix[i][k] -= c * matrix[j][k];
				inverse[i][k] -= c * inverse[j][k];
			}
		}
	}
	
	for (int n = 0; n < N; n++) {
		double c = matrix[n][n];
		for (int k = 0; k < N; k++) {
			matrix[n][k] /= c;
			inverse[n][k] /= c;
		}
	}
	
	outFile << fixed;
	outFile << setprecision(6);
	
	outFile << N << ' ' << N << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			outFile << inverse[i][j] << (j == N - 1 ? '\n' : ' ');
		}
	}
	
	inFile.close();
	outFile.close();
	return 0;
}

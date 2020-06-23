#include <iostream>
#include <fstream>
using namespace std;

int indices[21];
int V[21][301];
int Elt[21][301][21];
int nums[21][301];
int weights[21];
int values[21];

int Knapsack(int N, int W) {
	if (N == 1) {
		if (W < weights[N]) {
		    return 0;
		} else {
			Elt[N][W][0] = indices[N];
			nums[N][W] = 1;
		    return values[N];
		}
	}

	if (V[N][W] != -1) {
		return V[N][W];
	}

	if (W < weights[N]) {
		V[N][W] =  Knapsack(N - 1, W);
		nums[N][W] = nums[N - 1][W];
		for (int k = 0; k < nums[N - 1][W]; k++) {
			Elt[N][W][k] = Elt[N - 1][W][k];
			nums[N][W]++;
		}
		return V[N][W];
	}
	
	int val1 = Knapsack(N - 1, W);
	int val2 = Knapsack(N - 1, W - weights[N]) + values[N];

	if (val1 > val2) {
		V[N][W] = val1;
		nums[N][W] = nums[N - 1][W];
		for (int k = 0; k < nums[N - 1][W]; k++) {
			Elt[N][W][k] = Elt[N - 1][W][k];
		}
	} else {
		V[N][W] = val2;
		nums[N][W] = nums[N - 1][W - weights[N]];
		for (int k = 0; k < nums[N - 1][W]; k++) {
			Elt[N][W][k] = Elt[N - 1][W - weights[N]][k];
		}
		Elt[N][W][nums[N][W]++] = indices[N];
	}
	
	return V[N][W];
}

int main() {
	int W, N;
 	fstream inFile, outFile;
 	inFile.open("Program1Input.txt", ios::in);
 	outFile.open("Program1Output.txt", ios::out);
	
	inFile >> W >> N;
	
	for (int i = 1; i <= N; i++) {
		inFile >> indices[i];
		inFile >> values[i] >> weights[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			V[i][j] = -1;
		}
	}
	
	int maxVal = Knapsack(N, W);
	outFile << maxVal << '\n';
	outFile << nums[N][W] << '\n';
	for (int i = 0; i < nums[N][W]; i++) {
		outFile << Elt[N][W][i] << (i != nums[N][W] - 1 ? " " : "");
	}
	
 	inFile.close();
 	outFile.close();
	return 0;
}

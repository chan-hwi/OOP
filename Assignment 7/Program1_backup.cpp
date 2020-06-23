#include <iostream>
#include <fstream>
using namespace std;

int** V;
bool** C;
int weights[21];
int values[21];

int Knapsack(int N, int W, int* arr, int* curIndex, bool isRoot = true) {
	if (N == 1) {
		if (W < weights[N]) {
		    return 0;
		} else {
		    arr[(*curIndex)++] = 1;
		    return values[N];
		}
	}
	if (W < weights[N]) {
		return Knapsack(N - 1, W, arr, curIndex);
	}
	if (V[N][W] != -1) {
		if (C[N][W]) arr[(*curIndex)++] = N;
		return V[N][W];
	}
	int* subArr1 = new int[N];
	int* subArr2 = new int[N];
	int* subIndex1 = new int;
	int* subIndex2 = new int;
	*subIndex1 = *subIndex2 = 0;
	
	int val1 = Knapsack(N - 1, W, subArr1, subIndex1, false);
	int val2 = Knapsack(N - 1, W - weights[N], subArr2, subIndex2, false) + values[N];
	if (val1 > val2) {
		V[N][W] = val1;
		for (int i = 0; i < *subIndex1; i++) {
		    arr[i] = subArr1[i];
		}
		*curIndex = *subIndex1;
	} else {
		V[N][W] = val2;
		C[N][W] = true;
		for (int i = 0; i < *subIndex2; i++) {
		    arr[i] = subArr2[i];
		}
		*curIndex = *subIndex2;
		arr[(*curIndex)++] = N;
	}
	if (!isRoot) {
	    delete[] subArr1;
	    delete[] subArr2;
	    delete subIndex1;
	    delete subIndex2;
	}
	
	return V[N][W];
}

int main() {
	int W, N;
 	fstream inFile, outFile;
 	inFile.open("Program1Input.txt", ios::in);
 	outFile.open("Program1Output.txt", ios::out);
	
	inFile >> W >> N;
	
	V = new int* [N + 1];
	C = new bool* [N + 1];
	for (int i = 1; i <= N; i++) {
		V[i] = new int[W + 1];
		C[i] = new bool[W + 1];
		for (int j = 1; j <= W; j++) {
			V[i][j] = -1;
			C[i][j] = false;
		}
	}
	
	for (int i = 0; i < N; i++) {
		int index;
		inFile >> index;
		inFile >> values[index] >> weights[index];
	}
	
	int *Items = new int[N + 1];
	int *curIndex = new int;
	*curIndex = 0;
	
	int maxVal = Knapsack(N, W, Items, curIndex);
	outFile << maxVal << '\n';
	outFile << *curIndex << '\n';
	for (int i = 0; i < *curIndex; i++) {
		outFile << Items[i] << (i != *curIndex - 1 ? " " : "");
	}
	
	delete curIndex;
	delete []Items;
	
	for (int i = 1; i <= N; i++) {
		delete[] V[i];
		delete[] C[i];
	}
	delete[] V;
	delete[] C;
	
	
 	inFile.close();
 	outFile.close();
	return 0;
}

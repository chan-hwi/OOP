#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double num;
	cin >> num;
	cout << fixed;
	cout << setprecision(6);
	cout << pow(num, 0.5);
	return 0;
}
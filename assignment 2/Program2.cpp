// 20191339 chanhwiHwang
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double num;
	cin >> num;

 	// set the location of floating point to N.xxxxxx
	cout << fixed;
	cout << setprecision(6);

	// finding square root of num
	cout << sqrt(num);
	return 0;
}
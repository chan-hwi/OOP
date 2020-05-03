// 20191339 chanhwiHwang
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	
	// Set seed of rand()
	srand((unsigned int)time(0));
	// To get more various random values since first value of rand() seems similar to each test
	rand();
	// set floating point location to N.xxxxxx by rounding 7th-decimal from point.
	cout << setprecision(6);
	cout << fixed;

	for (int i = 0; i < 3; i++) {
		cout << rand() % 32768 / 32767.0 << ' ';  // Since maximum value of rand() varies from compilers, I set the value below 32767 and dividing it to real number ranges from 0 to 1
	}
	cout << endl;
	return 0;
}

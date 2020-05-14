// 20191339 chanhwiHwang
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	
	// Set seed of rand()
	srand((unsigned int)time(0));
	// set floating point location to 0.xxxxxx by rounding 7th-decimal from point.
	cout << setprecision(6);
	cout << fixed;

	for (int i = 0; i < 3; i++) {
		// Since maximum value of rand() varies from compilers, I divided it with RAND_MAX, maximum value of rand(), to get real number ranges from 0 to 1
		cout << rand() / (double)RAND_MAX << ' ';  
	}
	cout << '\n';
	return 0;
}

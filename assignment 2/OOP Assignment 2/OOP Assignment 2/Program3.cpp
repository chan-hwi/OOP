#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
	srand((unsigned int)time(0));
	rand();
	cout << setprecision(6);
	cout << fixed;
	for (int i = 0; i < 3; i++) {
		cout << rand() / 32767.0 << ' ';
	}
	return 0;
}
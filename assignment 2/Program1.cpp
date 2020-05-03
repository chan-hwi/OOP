// 20191339 chanhwiHwang
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b; // receiving inputs
	if (a > b) {
		cout << 0 << endl;
	} else {
		int sum = 0;
		for (int i = a; i <= b; i++) {  // finding sum of numbers between a and b
			sum += i;
		}
		cout << sum << endl;
	}
	return 0;
}


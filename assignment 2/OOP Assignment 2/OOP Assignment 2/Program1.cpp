#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b) {
		cout << 0 << endl;
	} else {
		int sum = 0;
		for (int i = a; i <= b; i++) {
			sum += i;
		}
		cout << sum << endl;
	}
	return 0;
}


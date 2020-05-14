// 20191339 chanhwiHwang
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b; // receiving inputs
	if (a > b) cout << 0 << '\n';
	else cout << (a+b)*(b-a+1)/2 << '\n'; // Finding sum of a ~ b using Gaussian sum
	return 0;
}


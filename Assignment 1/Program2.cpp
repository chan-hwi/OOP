//20191339 ChanHwiHwang
#include <iostream>

using namespace std;

int main() {
	char c;
	cout << "Enter your character :";
	cin.get(c);
	cout << "Typed character's ASCII code is " << static_cast<int>(c) << endl;
	return 0;
}

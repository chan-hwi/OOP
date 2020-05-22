#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;
	
	fstream inFile;
	inFile.open("Input.txt", ios::in);
	
	int count = 0;
	string str;
	while (!inFile.fail()) {
		inFile >> str;
		if (str.length() != word.length()) continue;
		bool isSame = true;
		for (int i = 0; i < str.length(); i++) {
			if (tolower(str[i]) != tolower(word[i])) {
				isSame = false;
				break;
			}
		}
		if (isSame) count++;
	}
	inFile.close();
	
	cout << count << '\n';
}

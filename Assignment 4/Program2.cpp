//20191339 ChanhwiHwang
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;  // read a specific word to count
	
	fstream inFile;
	inFile.open("Paragraph.txt", ios::in);
	
	int count = 0;
	string str;  // string buffer to store each word from "inFile" input file stream
	while (!inFile.fail()) {  // the case when it fails to read such as reaching the end of the file
		inFile >> str;
		if (str.length() != word.length()) continue;  // skip when lengths of them are different
		bool isSame = true;  // to distinguish breaked case and completed case
		for (int i = 0; i < str.length(); i++) {
			if (tolower(str[i]) != tolower(word[i])) {  // comparing character of each string sequentially
				isSame = false;  // breaked case : there's different character -> isSame = false
				break;
			}
		}  // completed case : all characters are same(not meeting break) -> isSame = true
		if (isSame) count++;  // In case with not meeting break, increases the count
	}
	inFile.close();  // closing file stream
	
	cout << count << '\n';
}

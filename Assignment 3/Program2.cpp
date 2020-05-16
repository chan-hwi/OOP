//20191339 ChanhwiHwang
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int c;
    cin >> c;
    if (c <= 1) { // When c is zero or one, it is not a prime number
        cout << 0 << '\n';
        return 0;
    }
    if (c == 2) { // When c is two, it is a prime number
        cout << 1 << '\n';
        return 0;
    }
    // Repeatedly find dividable number from 2(smallest prime number) to greatest integer smaller than square root of c
    // Since when it becomes bigger than sqrt(c), the last part is same as previous one. ex) 12 = 3(divider) * 4, when divider becomes 4, 4 > sqrt(12) => 12 = 4(divider) * 3 => same as previous one
    for (int i = 2; i <= sqrt(c); i++) { 
        if (c % i == 0) { // When c is dividable by some integer
            cout << 0 << '\n'; // c is not a prime number
            return 0;
        }
    }
    cout << 1 << '\n'; // When there is no integer that can divide c, c is a prime number
    return 0;
}
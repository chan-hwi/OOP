//20191339 ChanhwiHwang
#include <iostream>
using namespace std;

int main() {
    int a, b, sum = 0; // Define input variables and variable to store the sum of numbers between a and b
    cin >> a >> b;
    if (a > b) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = a; i <= b; i++) { // Repeatedly add i to sum to find sums between a and b inclusive
        sum += i;
    }
    cout << sum << '\n';
    return 0;
}
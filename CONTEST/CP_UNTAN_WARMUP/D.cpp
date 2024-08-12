#include <iostream>
#include <iomanip>
using namespace std;

int factorial(int x) {
    int result = x;
    if (x == 0) {
        result = 1;
    }
    while (x > 1) {
        result *= --x;
    }
    
    return result;
}

int main() {
    int k, y; cin >> k >> y;
    int a = 2*k;
    int b = y - 3;
    int cara = factorial(b) / factorial(3);
    // int cara = (factorial(a) / (factorial(b) * factorial(a - b)));
    cout << cara << endl;
    
    return 0;
}
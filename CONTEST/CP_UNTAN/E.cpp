#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    string s = "0";
    int x = 1; // number of digits added to s

    if (n % 2 == 1 ) {
        s += "1";
        x++;
    }

    int temp = 0; //to generate digit from 1-9
    while (x < n - 1) {
        int digit = (temp % 9) + 1;
        for (int i = 0; i < 2; i++) {
            s += to_string(digit);
            x++;
        }
        temp++;
    }

    int sod = 0; //sum of digit
    for (auto &ch : s) {
        sod += (ch - '0');
    }
    
    s.insert(1, to_string(9 - (sod %  9)));
    cout << s << endl;
    
    return 0;
}
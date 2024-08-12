#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int i, j; cin >> i >> j;
    cout << (s[i-1] == s[j-1] ? "TIDAK" : "YA") << endl;
    
    return 0;
}
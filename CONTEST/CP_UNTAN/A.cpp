#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            count++;
        } else {
            break;
        }
    }
    s.erase(0, count);
    cout << s << endl;
    
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        long double a, b; cin >> a >> b;
        long double result = (a + b) / 2.0;
        string str = to_string(result);
        // cout << fixed << showpoint << result << endl;

        int count = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] == '0') count++;
            else break;
        } 
        
        str.erase(str.length() - count, str.length() - 1);
        if (str.back() == '.') {
            str.pop_back();
        }
        cout << str << endl;
    }
    
    return 0;
}
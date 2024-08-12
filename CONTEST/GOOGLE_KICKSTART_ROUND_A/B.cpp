#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string num; cin >> num;
        ll count = 0;
        for (auto& digit : num) {
            count += (digit - '0');
        }
        int new_digit = (9 - (count % 9)) % 9;
        int stop = 0;
        if (new_digit == 0) {
            stop = 1;
        } else {
            for (auto& digit : num) {
                if (new_digit < (digit - '0')) {
                    break;
                }
                stop++;
            }
        }
        
        cout << "Case #" << t << ": " << num.substr(0, stop) << new_digit << num.substr(stop, num.length() - stop) << "\n";
    }

    return 0;
}
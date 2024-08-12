#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll a, b; cin >> a >> b;
        vector<bool> divisible(b-a+1, false);
        ll count = 0;
        for (ll num = a; num <= b; num++) {
            ll loc = num-a;
            if (divisible[loc]) continue;

            string num_str = to_string(num);
            ll sod = 0;
            ll mod = 1;
            bool OK = false;
            for(auto& digit : num_str) {
                if (digit == '0') {
                    OK = true;
                    break;
                }
                sod += (digit - '0');
                mod *= (digit - '0');
            }
            if (OK) count++;
            else if (mod % sod == 0) {
                do {
                    ll index = stoll(num_str) - a;
                    if (index > b-a) break;
                    divisible[index] = true;
                    count++;
                } while (next_permutation(num_str.begin(), num_str.end()));
            }
        }
        cout << "Case #" << t << ": " << count << "\n";
    }

    return 0;
}
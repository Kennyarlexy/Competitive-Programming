#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    ll t = 0;
    while (true) {
        cin >> s;
        if (s == "end") break;

        vector<ll> A;
        for (auto& ch : s) {
            if (!A.empty() && ch <= A.back()) {
                ll i = lower_bound(A.begin(), A.end(), ch) - A.begin();
                A[i] = ch;
            } else {
                A.push_back(ch);
            }

            // for (auto d : A) {
            //     cout <<(char)  d << " ";
            // }
            // cout << "\n";
        }

        cout << "Case " << ++t << ": " << A.size() << "\n";
    }
    
    return 0;
}
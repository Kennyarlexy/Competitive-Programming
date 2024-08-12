#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string target;
ll n;
map<string, bool> dp;
string bank[1005];

bool dpf(string T) {
    if (T == "") return true;
    auto itr = dp.find(T);
    if (itr != dp.end()) return itr->second;

    for (ll i = 1; i <= n; i++) {
        if (T.substr(0, bank[i].length()) != bank[i]) continue;
        string sub = T.substr(bank[i].length());
        if (dpf(sub)) {
            dp[T] = true;
            return true;
        } 
    }

    dp[T] = false;
    return false;
}

int main() {
    fast_io();
    //use ll when possible!
    cin >> target >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> bank[i];
    }

    if (dpf(target)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
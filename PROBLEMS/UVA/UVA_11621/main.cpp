#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll pow_2[32], pow_3[32];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pow_2[0] = pow_3[0] = 1;
    for (int i = 1; i <= 31; i++) {
        pow_2[i] = pow_2[i-1]*2;
        pow_3[i] = pow_3[i-1]*3;
    }
    
    vector<ll> all;
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; pow_2[i] * pow_3[j] <= pow_2[31]; j++) {
            all.push_back(pow_2[i] * pow_3[j]);
        }
    }

    sort(all.begin(), all.end());
    
    ll m; 
    while (cin >> m && m) {
        auto itr = lower_bound(all.begin(), all.end(), m);
        cout << *itr << "\n";
    }
    
    return 0;
}

/*
100
108
1000
3000
0
*/
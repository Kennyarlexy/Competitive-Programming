#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> MP;
    
    int n, Q; cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        MP[s] = i;
    }

    for (int q = 1; q <= Q; q++) {
        string s; cin >> s;
        if (MP.count(s)) cout << MP[s] << "\n";
        else cout << "-1\n";
    }
    
    return 0;
}
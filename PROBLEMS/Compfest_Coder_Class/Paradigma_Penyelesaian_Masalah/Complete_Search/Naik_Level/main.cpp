#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[25];
ll n, m; 

bool f(int i, ll x) {
    if (i > n) return x == m;

    if (x + A[i] <= m) {
        if (f(i+1, x + A[i])) return true;
    }

    return f(i+1, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    bool OK = f(1, 0);
    if (OK) cout << "bisa\n";
    else cout << "tidak bisa\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (A[i] > A[j]) cnt++;
        }
    }

    cout << cnt << "\n";
    
    return 0;
}
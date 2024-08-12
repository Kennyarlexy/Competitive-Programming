#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    unordered_map<int, int> MP;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    for (int k = 1; k <= n; k++) {
        MP[A[i]*A[j] + A[k]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    for (int k = 1; k <= n; k++) {
        if (A[i] == 0) continue;
        ans += MP[A[i]*(A[j] + A[k])];
    }

    cout << ans << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<int> A(n+5, 0);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            char ch = A[x] + 'a';
            cout << ch;
            A[x]++;
        }
        cout << "\n";
    }
    
    return 0;
}
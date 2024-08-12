#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[200005], B[200005], C[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }

        iota(C+1, C+n+1, 1);
        sort(C+1, C+n+1, [] (int i, int j) {
            return A[i] < A[j];
        });
        
        for (int i = 1; i <= n; i++) {
            cout << A[C[i]] << " \n"[i==n]; 
        }

        for (int i = 1; i <= n; i++) {
            cout << B[C[i]] << " \n"[i==n];
        }
    }
    
    return 0;
}
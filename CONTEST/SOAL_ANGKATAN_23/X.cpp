#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[200005], B[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, R; cin >> N >> R;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(A+1, A+N+1);
    ll x = 0;
    ll y = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] > x) {
            y += (A[i] - (x+1));
            x++;
        }
    }

    R = y - R; //fgs
    ll z = 0;
    for (int i = 1; i <= N; i++) {
        if (B[i] == R) z++;
    }

    cout << y << "\n" << z << "\n";
    
    return 0;
}
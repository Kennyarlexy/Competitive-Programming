#include <bits/stdc++.h>
#define ll long long
#define Point pair<ll, ll>
#define fi first
#define se second
using namespace std;

ll A[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        map<ll, ll> MP;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            MP[A[i]]++;
        }
        
        set<ll> S;
        for (int i = 0; i <= n; i++) {
            S.insert(i);
        }

        S.erase(A[1]);
        MP[A[1]]--;
        int j = n-1;
        bool f = true;
        for (int i = 2; i < n; i++) {
            ll mex = *S.begin();
            if (MP[mex] == 0) {
                j = i-1;
                break;
            }

            MP[A[i]]--;
            if (A[i] < mex && MP[A[i]] == 0) {
                f = false;
                break;
            }

            if (S.count(A[i])) S.erase(A[i]);
        }

        if (!f) {
            cout << "-1\n";
        } else {
            bool g = true;
            if (j == n-1) {
                ll x = *S.begin();
                ll y = (A[n] == 0 ? 1 : 0);
                if (x != y) g = false;
            }

            if (g) {
                cout << "2\n";
                cout << "1 " << j << "\n";
                cout << j+1 << " " << n << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
    
    return 0;
}
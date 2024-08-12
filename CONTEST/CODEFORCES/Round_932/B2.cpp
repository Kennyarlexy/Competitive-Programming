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

        int j = -1;
        bool f = false;
        for (int i = 1; i < n; i++) {
            MP[A[i]]--;
            if (S.count(A[i])) S.erase(A[i]);

            ll mex = *S.begin();
            if (A[i] < mex && MP[A[i]] == 0) break;

            if (MP[mex] == 0) {
                f = true;
                j = i;
                break;
            }
        }

        if (f) {
            cout << "2\n";
            cout << "1 " << j << "\n";
            cout << j+1 << " " << n << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
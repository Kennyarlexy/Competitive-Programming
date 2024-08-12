#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

pair<ll, ll>  A[100005], B[100005], C[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            A[i] = {a, i};
        }

        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            B[i] = {a, i};
        }

        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            C[i] = {a, i};
        }

        sort(A+1, A + n + 1, greater<pair<ll, ll>>());
        sort(B+1, B + n + 1, greater<pair<ll, ll>>());
        sort(C+1, C + n + 1, greater<pair<ll, ll>>());

        // vector<pair<ll, ll>> vect_A, vect_B, vect_C;

        // for (int i = 1; i <= 3; i++) {
        //     vect_A.push_back(A[i]);
        //     vect_B.push_back(B[i]);
        //     vect_C.push_back(C[i]);
        // }

        ll _max = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (A[i].se == B[j].se || A[i].se == C[k].se || B[j].se == C[k].se) continue;

                    _max = max(_max, A[i].fi + B[j].fi + C[k].fi);
                }
            }
        }

        cout << _max << "\n";
    }
    
    return 0;
}
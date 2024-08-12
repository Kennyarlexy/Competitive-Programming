#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[755][755];
ll B[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    while (cin >> k) {
        ll sum = 0;
        for (ll i = 1; i <= k; i++) {
            for (ll j = 1; j <= k; j++) {
                cin >> A[i][j];
            }
            sort(A[i]+1, A[i]+k+1);
            B[i] = A[i][1];
            sum += B[i];
        }

        multiset<pair<ll, ll>> PQ;
        for (ll i = 1; i <= k; i++) {
            for (ll j = 2; j <= k; j++) {
                if (PQ.size() == k-1) {
                    auto top = PQ.end();
                    top--;
                    if (A[i][j] < (*top).fi) {
                        PQ.erase(top);
                        PQ.insert({A[i][j], i});
                    }
                } else {
                    PQ.insert({A[i][j], i});
                }
            }
        }

        for (auto& d : PQ) {
            cout << d.fi << " ";
        }
        cout << "\n------------------";

        cout << sum;
        for (auto& d : PQ) {
            sum -= B[d.se];
            sum += d.fi;
            B[d.se] = d.fi;
            cout << " " << sum;
        }
        cout << "\n";
    }

    return 0;
}

/*
3
1 8 5
9 2 5
10 7 6
2
1 1
1 2
*/
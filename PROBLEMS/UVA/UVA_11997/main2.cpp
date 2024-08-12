#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[755][755];

struct cmp {
    bool operator () (pair<ll, ll> A, pair<ll, ll> B) {
        return B.fi < A.fi;
    }
};

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
            sum += A[i][1];
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> PQ;
        for (ll i = 1; i <= k; i++) {
            PQ.push({A[i][2] - A[i][1], 2});
        }

        cout << sum;
        for (ll i = 2; i <= k; i++) {
            auto top = PQ.top(); PQ.pop();
            sum += top.fi;
            PQ.push({A[top.se+1] - A[top.se], top.se+1});
            cout << " " << sum;
        }
        cout << "\n";
    }
    
    return 0;
}
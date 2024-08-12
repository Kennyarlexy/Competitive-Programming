#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[755][755];
ll res[755];
struct entry {
    ll sum, iP, iQ;
};

struct cmp {
    bool operator () (entry A, entry B) {
        return B.sum < A.sum;
    }
};

void f(ll P[755], ll Q[755], ll k) {
    priority_queue<entry, vector<entry>, cmp> PQ;
    for (ll i = 1; i <= k; i++) {
        PQ.push({P[i]+Q[1], i, 1});
    }

    ll i = 0;
    while (i < k) {
        i++;
        auto top = PQ.top(); PQ.pop();
        res[i] = top.sum;
        PQ.push({P[top.iP]+Q[top.iQ+1], top.iP, top.iQ+1});
    }

    for (ll i = 1; i <= k; i++) {
        Q[i] = res[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    while (cin >> k) {
        for (ll i = 1; i <= k; i++) {
            for (ll j = 1; j <= k; j++) {
                cin >> A[i][j];
            }

            sort(A[i]+1, A[i]+k+1);
        }

        for (ll i = 2; i <= k; i++) {
            f(A[i-1], A[i], k);
        }

        for (ll i = 1; i <= k; i++) {
            cout << A[k][i] << " \n"[i==k];
        }
    }
    
    return 0;
}
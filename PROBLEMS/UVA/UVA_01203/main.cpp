#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

struct query {
    ll Q, P, t;
};

struct cmp {
    bool operator () (query A, query B) {
        if (B.t == A.t) {
            return B.Q < A.Q;
        }
        return B.t < A.t;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string cmd;
    priority_queue<query, vector<query>, cmp> PQ;
    while (true) {
        cin >> cmd;
        if (cmd == "#") break;
        ll Q, P; cin >> Q >> P;
        PQ.push({Q, P, P});
    }

    ll K; cin >> K;
    for (ll i = 1; i <= K; i++) {
        auto top = PQ.top(); PQ.pop();
        cout << top.Q << "\n";
        top.t += top.P;
        PQ.push(top);
    }
    
    return 0;
}
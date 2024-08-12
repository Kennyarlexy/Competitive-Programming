#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct entry {
    string name;
    ll f, p, t;
};

struct cmp {
    bool operator () (entry A, entry B) {
        if (A.t == B.t) {
            return B.p < A.p;
        }
        return B.t < A.t;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        priority_queue<entry, vector<entry>, cmp> PQ;
        ll n, k; cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            string name; ll f;
            cin >> name >> f;
            PQ.push({name, f, i, f});
        }

        for (ll i = 1; i <= k; i++) {
            auto top = PQ.top(); PQ.pop();
            cout << top.t << " " << top.name << "\n";
            top.t += top.f;
            PQ.push(top);
        }
    }
    
    return 0;
}
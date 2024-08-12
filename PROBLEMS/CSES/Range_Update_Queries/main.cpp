#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define LSOne(x) ((x) & (-x))
ll A[200005];
struct RUPQ {
    vector<ll> ft;
    int n;

    RUPQ(int n) : ft(n+5) {
        this->n = n;
    }

    void update(int i, int d) {
        if (i <= 0) return;

        while (i <= n) {
            ft[i] += d;
            i += LSOne(i);
        }
    }
    
    void update(int i, int j, ll d) {
        update(i, d);
        update(j+1, -d);
    }

    ll query(int i) {
        ll X = 0;
        while (i > 0) {
            X += ft[i];
            i -= LSOne(i);
        }
        return X;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q; cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> A[i];

    RUPQ fenwick(n);
    // for (int i = 1; i <= n; i++) {
    //     cout << A[i] << " \n"[i==n];
    // }

    // for (int i = 1; i <= n; i++) {
    //     cout << fenwick.ft[i] << " \n"[i==n];
    // }
    // cout << "---------------\n";
    for (int q = 1; q <= Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int a, b, u; cin >> a >> b >> u;
            fenwick.update(a, b, u);
        } else {
            int k; cin >> k;
            cout << A[k] + fenwick.query(k) << "\n";
        }
    }

    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005], B[200005];
#define LSOne(x) ((x) & (-x))
struct RURQ {
    vector<ll> ft1, ft2; //ft1 (+), ft2 (-)
    int n;

    RURQ(int n) : ft1(n+5), ft2(n+5) {
        this->n = n;
    }

    void update(int i, int j, ll d) {
        // RUPQ part
        update(i, d, ft1);
        update(j+1, -d, ft1);

        // PURQ part
        update(i, (i-1)*d, ft2);
        update(j+1, -j*d, ft2);
    }

    void update(int i, int d, vector<ll> &ft) {
        while (i <= n) {
            ft[i] += d;
            i += LSOne(i);
        }
    }

    ll query(int i, int j) {
        ll X = query(j) - query(i-1);
        return X;
    }

    ll query(int i) {
        ll X = i*query(i, ft1) - query(i, ft2);
        return X;
    }

    ll query(int i, vector<ll> &ft) {
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
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B[i] = B[i-1] + A[i];
    }

    RURQ fenwick(n);
    for (int q = 1; q <= Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            ll a, b, x; cin >> a >> b >> x;
            fenwick.update(a, b, x);
        } else {
            ll k; cin >> k;
            cout << B[k] - B[k-1] + fenwick.query(k, k) << "\n";
        }
    }
    
    return 0;
}

/*
6 3
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
*/
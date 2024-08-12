#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
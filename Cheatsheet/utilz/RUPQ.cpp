#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define LSOne(x) ((x) & (-x))
struct RUPQ {
    vector<ll> ft;
    int n;

    RUPQ(int n) : ft(n+5) {
        this->n = n;
    }

    void update(int i, int d) {
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

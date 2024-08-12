#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005];

// with lazy propagation
struct SegmentTree {
    vector<ll> st, lazy;
    int n;
    
    // n must be a power of 2, elements in array A are 1-indexed
    SegmentTree(int n) : st(2*n), lazy(2*n) {
        this->n = n;
        build(1, 1, n);
    }

    int l(int p) {return (p << 1); }
    int r(int p) {return (p << 1) + 1; }

    // optional, add conquer function to merge 2 subtree if merge is not simple

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
            return;
        }

        int M = (L + R) / 2, lp = l(p), rp = r(p);
        build(lp, L, M);
        build(rp, M+1, R);
        st[p] = st[lp] + st[rp];
    }

    // lazy of children is merged in propagate
    void propagate(int p, int L, int R) {
        if (lazy[p] == 0) return;

        if (L != R) {
            int lp = l(p), rp = r(p);
            lazy[lp] += lazy[p];
            lazy[rp] += lazy[p];
        }

        st[p] += lazy[p] * (R-L+1); // add this to R-L+1 elements
        lazy[p] = 0;
    }

    void update(int p, int L, int R, int i, int j, ll d) {
        propagate(p, L, R);
        if (L >= i && R <= j) {
            lazy[p] += d;
            propagate(p, L, R);
            return;
        }

        if (max(L, i) > min(R, j)) return;

        int M = (L + R) / 2, lp = l(p), rp = r(p);
        update(lp, L, M, i, j, d);
        update(rp, M+1, R, i, j, d);
        st[p] = st[lp] + st[rp];
    }

    void update(int i, int j, int d) {
        update(1, 1, n, i, j, d);
    }

    ll query(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (L >= i && R <= j) return st[p];
        if (max(L, i) > min(R, j)) return 0; // ignore this range, return value depends

        int M = (L + R) / 2, lp = l(p), rp = r(p);
        return query(lp, L, M, i, j) + query(rp, M+1, R, i, j); // or use conquer
    }

    ll query(int i, int j) {
        return query(1, 1, n, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 17;

    for (int i = 1; i <= n; i++) A[i] = 1; // sample
    int nn = (__builtin_popcount(n) == 1) ? n : (1 << __bit_width(n));
    SegmentTree segmentTree(nn);

    // segmentTree.update(1, 17, 1);
    segmentTree.update(1, 10, 1);
    segmentTree.update(11, 17, 1);
    segmentTree.update(1, 17, -1);

    for (int len = 8; len <= 10; len++) {
        for (int L = 1; L + len - 1 <= 17; L++) {
            int R = L + len - 1;
            cout << "sum[" << L << "..." << R << "] = " << segmentTree.query(L, R) << "\n";
        }
    }

    cout << segmentTree.query(1, 8) << " " << segmentTree.query(1, 1) << "\n";
    cout << "OK\n";
    
    return 0;
}
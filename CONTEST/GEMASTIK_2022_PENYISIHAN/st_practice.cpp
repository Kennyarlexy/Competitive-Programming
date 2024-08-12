#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> A(100005);

struct SegmentTree {
    vector<int> st, lazy;
    int N; // pow of 2
    SegmentTree(int N) : st(2*N+5), lazy(2*N+5) {
        this->N = N;
        build(1, 1, N);
    }

    int l(int p) {
        return (p << 1);
    }

    int r(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
            return;
        }
        int M = (L + R) / 2;
        build(l(p), L, M);
        build(r(p), M+1, R);
        st[p] = st[l(p)] + st[r(p)];
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] == 0) return;

        int len = R - L + 1;
        st[p] += len*lazy[p];
        if (L != R) {
            lazy[l(p)] += lazy[p];
            lazy[r(p)] += lazy[p];
        }
        lazy[p] = 0;
    }

    ll query(int p, int L, int R, int i, int j) {
        if (max(L, i) > min(R, j)) return 0;

        propagate(p, L, R);
        if (L >= i && R <= j) return st[p];

        int M = (L + R) / 2;
        return query(l(p), L, M, i, j) + query(r(p), M+1, R, i, j);
    }

    ll query(int i, int j) {
        return query(1, 1, N, i, j);
    }

    void update(int p, int L, int R, int i, int j, int v) {
        if (max(L, i) > min(R, j)) return;
        
        if (L >= i && R <= j) {
            lazy[p] += v;
            propagate(p, L, R);
            return;
        }

        propagate(p, L, R);
        int M = (L + R) / 2;
        update(l(p), L, M, i, j, v);
        update(r(p), M+1, R, i, j, v);
        st[p] = st[l(p)] + st[r(p)];
    }

    void update(int i, int j, int v) {
        if (v == 0) return;
        update(1, 1, N, i, j, v);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int N = (__builtin_popcount(n) == 1 ? n : (1 << __bit_width(n)));
    A.resize(N+5);

    auto tree = SegmentTree(N);

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int x, L, R; cin >> x >> L >> R;
        
        if (x == 1) {
            cout << tree.query(L, R) << "\n";
        } else {
            int v; cin >> v;
            tree.update(L, R, v);
        }
    }

    cout << A.capacity() << "\n";
    
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
23
1 1 10
1 1 5
1 6 10
2 1 10 1
1 1 10
1 1 5
1 6 10
2 1 10 2
1 1 10
1 1 5
1 6 10
2 1 10 -2
1 1 10
1 1 5
1 6 10
2 1 10 -1
1 1 10
1 1 5
1 6 10
2 10 10 100
1 1 10
1 1 5
1 6 10
*/
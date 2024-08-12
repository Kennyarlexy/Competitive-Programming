#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> A(200005);
ll pow_10[200005];
const ll MOD = 998244353;
// const ll MOD = LLONG_MAX;

struct SegmentTree {
    vector<vector<ll>> st;
    vector<ll> lazy;
    int N;

    SegmentTree(int N) : st(N*2, vector<ll> (11)), lazy(N*2) {
        this->N = N;
        build(1, 1, N);
    }

    int l(int p) {
        return (p << 1);
    }

    int r(int p) {
        return (p << 1) + 1;
    }

    void merge(vector<ll> &X, vector<ll> &Y, vector<ll> &Z, int k) {
        /*
            X: left vector
            Y: right vector
            Z: parent vector
            k: pow of 10
        */
        int a = X[10], b = Y[10];
        for (int i = 0; i < 10; i++) {
            Z[i] = (pow_10[k]*X[a++] + Y[b++]) % MOD;
            if (a == 10) a = 0;
            if (b == 10) b = 0;
        }
    }

    void create(vector<ll> &X, int x) {
        for (int i = 0; i < 10; i++) {
            X[i] = x++;
            if (x == 10) x = 0;
        }
    }

    void build(int p, int L, int R) {
        if (L == R) {
            create(st[p], A[L]);
            return;
        }

        int M = (L + R) / 2;
        int left = l(p), right = r(p);
        build(left, L, M);
        build(right, M+1, R);
        merge(st[left], st[right], st[p], R-M);
    }


    void propagate(int p, int L, int R) {
        if (lazy[p] == 0) return;

        st[p][10] = (st[p][10] + lazy[p]) % 10;
        if (L != R) {
            lazy[l(p)] += lazy[p];
            lazy[r(p)] += lazy[p];
        }

        lazy[p] = 0;
    }

    ll conquer(ll a, ll b, int k) {
        /*
            a: left query result
            b: right query result
            k: pow of 10
        */
        if (a == -1) return b;
        if (b == -1) return a;
        
        return (a*pow_10[k] + b) % MOD;
    }

    ll query(int p, int L, int R, int i, int j) {
        if (j < i) return -1;

        propagate(p, L, R);
        if (L >= i && R <= j) return st[p][st[p][10]];

        int M = (L + R) / 2;
        ll result = conquer(query(l(p), L, M, i, min(M, j)),
                            query(r(p), M+1, R, max(M+1, i), j),
                            j-M);
        
        return result;
    }

    void update(int p, int L, int R, int i, int j, int v) {
        if (max(L, i) > min(R, j)) return;
        
        if (L >= i && R <= j) {
            lazy[p] += v;
            propagate(p, L, R);
            return;
        }

        int M = (L + R) / 2;
        int left = l(p), right = r(p);
        update(left, L, M, i, j, v);
        update(right, M+1, R, i, j, v);
        merge(st[left], st[right], st[p], R-M);
        st[p][10] = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q; cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        A[i] = ch - '0';
    }
    
    pow_10[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        pow_10[i] = pow_10[i-1]*10 % MOD;
    }

    int N = (__builtin_popcount(n) == 1) ? n : (1 << __bit_width(n));

    auto tree = SegmentTree(N);

    for (int q = 1; q <= Q; q++) {
        int type, L, R; cin >> type >> L >> R;
        if (type == 1) {
            int v; cin >> v;
            tree.update(1, 1, N, L, R, v);
        } else {
            ll ans = tree.query(1, 1, N, L, R);
            cout << ans << "\n";
        }
    } 
    
    return 0;
}

/*
13 5
1234567890123
2 1 13
2 10 13
1 4 8 5
1 1 5 6
2 1 8

13 1
1234567890123
2 1 8

13 3
1234567890123
2 9 13
1 9 13 1
2 9 13

13 5
1234567890123
2 1 13
1 4 8 5
2 1 13
1 1 5 6
2 1 13

8 9
12345678
2 1 8
1 4 8 1
2 5 8
2 5 6
2 1 8
1 1 5 1
2 1 8
2 5 8
2 5 6

*/
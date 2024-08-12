#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int _a = 4, _b = 5, _c = 6, _x = 0, _y = 1, _z = 2;
const int _ab = 1, _ac = 2, _bc = 3;
const int _abc = 0;

struct SegmentTree {
    vector<vector<ll>> st, lazy;
    int N;
    SegmentTree(int N) : st(2*N, vector<ll> (7)), lazy(2*N, vector<ll> (4)) {
        this->N = N;
    }

    int l(int p) {return (p << 1);}
    int r(int p) {return (p << 1) + 1;}

    void propagate(int p, int L, int R) {
        if (lazy[p][3] == 0) return;

        ll k = R-L+1;

        // update abc
        (st[p][_abc] += st[p][_ab] * lazy[p][_z]) %= MOD;
        (st[p][_abc] += st[p][_ac] * lazy[p][_y]) %= MOD;
        (st[p][_abc] += st[p][_bc] * lazy[p][_x]) %= MOD;
        (st[p][_abc] += st[p][_a] * lazy[p][_y] % MOD * lazy[p][_z]) %= MOD;
        (st[p][_abc] += st[p][_b] * lazy[p][_x] % MOD * lazy[p][_z]) %= MOD;
        (st[p][_abc] += st[p][_c] * lazy[p][_x] % MOD * lazy[p][_y]) %= MOD;
        (st[p][_abc] += lazy[p][_x] * lazy[p][_y] % MOD * lazy[p][_z] % MOD * k) %= MOD;
        
        update_2(p, k); // update ab, ac, bc

        // update a, b, c
        (st[p][_a] += lazy[p][_x] * k) %= MOD;
        (st[p][_b] += lazy[p][_y] * k) %= MOD;
        (st[p][_c] += lazy[p][_z] * k) %= MOD;

        if (L != R) {
            int left = l(p);
            int right = r(p);
            (lazy[left][_x] += lazy[p][_x]) %= MOD;
            (lazy[left][_y] += lazy[p][_y]) %= MOD;
            (lazy[left][_z] += lazy[p][_z]) %= MOD;
            lazy[left][3] = 1;

            (lazy[right][_x] += lazy[p][_x]) %= MOD;
            (lazy[right][_y] += lazy[p][_y]) %= MOD;
            (lazy[right][_z] += lazy[p][_z]) %= MOD;
            lazy[right][3] = 1;
        }

        lazy[p][3] = lazy[p][_x] = lazy[p][_y] = lazy[p][_z] = 0;
    }

    void merge(vector<ll> &X, vector<ll> &Y, vector<ll> &Z) {
        for (int i = 0; i < 7; i++) {
            Z[i] = (X[i] + Y[i]) % MOD;
        }
    }

    void update_1(int p, int L, int R, int i, int j, int vx, int vy, int vz) {
        propagate(p, L, R);
        if (max(L, i) > min(R, j)) return;
        
        if (L >= i && R <= j) {
            lazy[p][_x] += vx;
            lazy[p][_y] += vy;
            lazy[p][_z] += vz;
            lazy[p][3] = 1;
            propagate(p, L, R);
            return;
        }

        int M = (L + R) / 2;
        int left = l(p), right = r(p);
        update_1(left, L, M, i, j, vx, vy, vz);
        update_1(right, M+1, R, i, j, vx, vy, vz);
        merge(st[left], st[right], st[p]);
    }

    void update_2(int p, ll k) {
        update_3(st[p][_ab], st[p][_a], st[p][_b], lazy[p][_x], lazy[p][_y], k);
        update_3(st[p][_ac], st[p][_a], st[p][_c], lazy[p][_x], lazy[p][_z], k);
        update_3(st[p][_bc], st[p][_b], st[p][_c], lazy[p][_y], lazy[p][_z], k);
    }

    void update_3(ll &ab, ll a, ll b, ll x, ll y, ll k) {
        (ab += y * a) %= MOD;
        (ab += x * b) %= MOD;
        (ab += y * x % MOD * k) %= MOD;
    }

    ll query() {
        return st[1][0];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q; cin >> n >> Q;

    int N = (__builtin_popcount(n) == 1) ? n : (1 << __bit_width(n));
    auto tree = SegmentTree(N);
    for (int q = 1; q <= Q; q++) {
        ll L, R, X, Y, Z;
        cin >> L >> R >> X >> Y >> Z;
        tree.update_1(1, 1, N, L, R, X, Y, Z);
        ll ans = tree.query();
        cout << ans << "\n";
    }
    
    return 0;
}
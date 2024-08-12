#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[1025005*2];

struct segTree {
    vector<int> st;
    vector<char> flag;
    int _size;

    int l(int p) {return (p << 1);}
    int r(int p) {return (p << 1) + 1;}

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
            return;
        }

        int M = (L+R)/2;
        build(l(p), L, M);
        build(r(p), M+1, R);
        st[p] = st[l(p)] + st[r(p)];
    }

    segTree(int size) : st(size*4), flag(size*4, 0), _size(size) {
        build(1, 0, _size-1);
    }

    void inverseFlag(ll p) {
        if (flag[p] == 'E') { // == 0
            flag[p] = 'F';
        } else if (flag[p] == 'F') { // == 1
            flag[p] = 'E';
        } else if (flag[p] == 'I') {
            flag[p] = 0;
        } else {
            flag[p] = 'I';
        }
    }

    void propagate(int p, int L, int R) {
        if (flag[p] == 0) return; 

        int M = (L+R)/2;
        if (L != R) {
            int lp = l(p);
            int rp = r(p);
            if (flag[p] == 'E' || flag[p] == 'F') {
                flag[lp] = flag[rp] = flag[p];
            } else {
                inverseFlag(lp);
                inverseFlag(rp);
            }
        }

        if (flag[p] == 'F') {
            st[p] = R-L+1;
        } else if (flag[p] == 'E') {
            st[p] = 0;
        } else if (flag[p] == 'I') {
            st[p] = R-L+1 - st[p];
        }
        flag[p] = 0;
    }

    void update(int p, int L, int R, int i, int j, char f) {
        propagate(p, L, R);
        if (L > j || R < i) return;
        if (L >= i && R <= j) {
            flag[p] = f;
            propagate(p, L, R);
        } else {
            int M = (L+R)/2;
            update(l(p), L, M, i, j, f);
            update(r(p), M+1, R, i, j, f);
            st[p] = st[l(p)] + st[r(p)];
        }
    }

    void update(int i, int j, char f) {
        update(1, 0, _size-1, i, j, f);
    }

    int RSQ(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (L > j || R < i) return 0;
        if (L >= i && R <= j) return st[p];

        int M = (L+R)/2;
        return RSQ(l(p), L, M, i, j) + RSQ(r(p), M+1, R, i, j);
    }

    int RSQ(int i, int j) {
        return RSQ(1, 0, _size-1, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int M; cin >> M;
        int i = 0;
        for (int m = 1; m <= M; m++) {
            int C; string s;
            cin >> C >> s;
            for (int c = 1; c <= C; c++) {
                for (auto& ch : s) {
                    A[i++] = (ch == '1' ? 1 : 0);
                }
            }
        }

        segTree st(i);

        int Q; cin >> Q;
        int cnt = 0;
        cout << "Case " << t << ":\n";
        for (int q = 1; q <= Q; q++) {
            char f; int i, j;
            cin >> f >> i >> j;
            if (f == 'S') {
                cout << "Q" << ++cnt << ": " << st.RSQ(i, j) << "\n";
            } else {
                st.update(i, j, f);
            }
        }
    }
    
    return 0;
}
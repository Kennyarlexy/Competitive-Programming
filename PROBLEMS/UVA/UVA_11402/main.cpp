#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[1024005*2];

struct segTree {
    vector<int> st;
    vector<char> flag;
    int _size;
    
    int l(int i) {return (i << 1);}
    int r(int i) {return (i << 1) + 1;}

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

    segTree(int size) : st(2*size+5), flag(2*size+5, 0) {
        build(1, 1, size);
        _size = size;
    }

    void updateThis(int p, int L, int R, char f) {
        if (f == 'E') {
            flag[p] = 'E';
            st[p] = 0;
        } else if (f == 'F') {
            flag[p] = 'F';
            st[p] = R-L+1;
        } else if (flag[p] == 'E') {
            flag[p] = 'F';
            st[p] = R-L+1;
        } else if (flag[p] == 'F') {
            flag[p] = 'E';
            st[p] = 0;
        } else {
            flag[p] = (flag[p] == 0 ? 'I' : 0);
            st[p] = R-L+1 - st[p];
        }
    }

    void propagate(int p, int L, int R) {
        //if leaf node or no flag, no need to propagate
        if (flag[p] == 0 || L == R) return;
        
        int lp = l(p);
        int rp = r(p);
        int M = (L+R)/2;
        updateThis(lp, L, M, flag[p]);
        updateThis(rp, M+1, R, flag[p]);
        flag[p] = 0;
    }

    void update(int p, int L, int R, int i, int j, char f) {
        // if not intersect, return
        if (R < i || L > j) return;
        if (L >= i && R <= j) {
            updateThis(p, L, R, f);
        } else {
            int M = (L+R)/2;
            propagate(p, L, R);
            update(l(p), L, M, i, j, f);
            update(r(p), M+1, R, i, j, f);

            st[p] = st[l(p)] + st[r(p)];
        }
    }

    int RSQ(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (L > j || R < i) return 0;
        if (L >= i && R <= j) return st[p];

        int M = (L+R)/2;
        return RSQ(l(p), L, M, i, j) + RSQ(r(p), M+1, R, i, j);
    }

    int RSQ(int i, int j) {
        return RSQ(1, 1, _size, i, j);
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
            int concat; string s;
            cin >> concat >> s;
            for (int c = 1; c <= concat; c++) {
                for (auto& ch : s) {
                    A[++i] = (ch == '1' ? 1 : 0);
                }
            }
        }

        int size = (1 << (int) ceil(log2(i)));
        while (i < size) A[++i] = 0;
        segTree st(size);

        int Q; cin >> Q;
        cout << "Case " << t << ":\n";
        int cnt = 0;
        for (int q = 1; q <= Q; q++) {
            char f; int i, j;
            cin >> f >> i >> j;
            if (f == 'S') {
                cout << "Q" << ++cnt << ": " << st.RSQ(i+1, j+1) << "\n";
            } else {
                st.update(1, 1, size, i+1, j+1, f);
            }
        }
    }

    return 0;
}
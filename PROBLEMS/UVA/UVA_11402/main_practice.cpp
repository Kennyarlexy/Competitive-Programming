/*
key of (lazy) segment tree:
- once we updateThis (update the current node in the tree), we remember what is previously done (this means updating or storing the flag), and no need to traverse further down
- ALWAYS  propagate if we need to traverse further down in order to make the child up-to-date first before visiting
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[1025005*2];

struct segTree {
    vector<int> st;
    vector<char> flag; // contains 4 possible flags: {0, 'F', 'E', 'I'}
    // if there is only 1 flag, we could use vector<bool>
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

    segTree(int size) : st(size*2), flag(size*2, 0), _size(size) {
        build(1, 0, _size-1);
    }

    void updateThis(int p, int L, int R, char f) {
        if (f == 'E') {
            flag[p] = 'E'; st[p] = 0;
        } else if (f == 'F') {
            flag[p] = 'F'; st[p] = R-L+1;
        } else { // flip!
            if (flag[p] == 'E') { // 1
                flag[p] = 'F'; st[p] = R-L+1;
            } else if (flag[p] == 'F') { // 0
                flag[p] = 'E'; st[p] = 0;
            } else {
                flag[p] = (flag[p] == 0 ? 'I' : 0);
                st[p] = R-L+1 - st[p];
            }
        }
        
    }

    void propagate(int p, int L, int R) {
        // if no flag or is a leaf node, no need to propagate
        if (flag[p] == 0 || L == R) return; 

        int M = (L+R)/2;
        updateThis(l(p), L, M, flag[p]);
        updateThis(r(p), M+1, R, flag[p]);
        flag[p] = 0;
    }

    void update(int p, int L, int R, int i, int j, char f) {
        // if [L..R] and [i..j] not intersect, return
        if (L > j || R < i) return;
        if (L >= i && R <= j) {
            updateThis(p, L, R, f);
            // no need to propagate here since we won't visit the child of p after this
        } else {
            propagate(p, L, R);
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
        // if [L..R] and [i..j] not intersect, return 0
        if (L > j || R < i) return 0;
        if (L >= i && R <= j) return st[p];

        propagate(p, L, R);
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

        int size = (1 << (int) ceil(log2(i)));
        while (i < size) A[i++] = 0;
        segTree st(size);

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
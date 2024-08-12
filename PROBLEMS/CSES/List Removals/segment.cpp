#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[400005];

struct SegmentTree {
    vector<int> st;
    int N;

    SegmentTree(int N) : st(2*N) {
        this->N = N;
    }

    int l(int p) {return (p << 1);}
    int r(int p) {return (p << 1) + 1;}

    void update(int p, int L, int R, int i) {
        if (i < L || i > R) return;
        if (L == R && i == L) {
            st[p]++;
            return;
        }

        int M = (L + R) / 2;
        update(l(p), L, M, i);
        update(r(p), M+1, R, i);
        st[p] = st[l(p)] + st[r(p)];
    }

    int search(int p, int L, int R, int x, int y) {
        if (L == R) return L;

        int M = (L + R) / 2;
        int left = l(p), right = r(p);
        if (M - (st[left] + y) < x) return search(right, M+1, R, x, y + st[left]);
        else return search(left, L, M, x, y);
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
    auto tree = SegmentTree(N);

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int y = tree.search(1, 1, N, x, 0);
        cout << A[y] << " \n"[i==n];
        tree.update(1, 1, N, y);
    }
    
    return 0;
}
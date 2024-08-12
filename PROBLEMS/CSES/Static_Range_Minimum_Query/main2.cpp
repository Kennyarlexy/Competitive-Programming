#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> class SparseTable {
  private:
    int n, log2dist;
    vector<vector<T>> st;

  public:
    T f(T l, T r){
        // imple here
        return min(l, r);
    }

    SparseTable(const vector<T> &v) {
        n = (int)v.size();
        log2dist = 1 + (int)log2(n);
        st.resize(log2dist);
        st[0] = v;
        for (int i = 1; i < log2dist; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    /** @return minimum on the range [l, r] */
    T query(int l, int r) {
        int i = (int)log2(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q; cin >> n >> Q;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    SparseTable<int> table(A);
    for (int q = 1; q <= Q; q++) {
        int l, r; cin >> l >> r;
        cout << table.query(l-1, r-1) << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define LSOne(x) ((x) & (-x))
template <typename T> 
    struct FenwickTree {
        vector<T> ft;
        // to create empty fenwick with size m
        FenwickTree(int m) : ft(m+5, 0) {}
        // create from vector
        FenwickTree(vector<T> &f) : ft(f.size()+5, 0) {build(f);}
    
        // vector f must also be 1-indexed
        void build(vector<T> &f) {
            for(int i = 1; i < f.size(); i++){
                ft[i] += f[i]; // 1-based
                if(i+LSOne(i) < f.size()){
                    ft[i+LSOne(i)] += ft[i];
                }
            }
        }

        // 1-indexed
        T rsq(int j) {
            T sum = 0;
            while (j > 0) {
                sum += ft[j];
                j -= LSOne(j);
            }
            return sum;
        }

        // 1-indexed
        T rsq(int i, int j) {
            return rsq(j) - rsq(i-1);
        }

        void update(int i, T d /*diff*/) {
            while (i < ft.size()) {
                ft[i] += d;
                i += LSOne(i);
            }
        }
    };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q; cin >> n >> Q;
    vector<ll> A(n+1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    FenwickTree<ll> fenwick(A);
    for (int q = 1; q <= Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;
            int d = u - A[k];
            A[k] = u;
            fenwick.update(k, d);
        } else {
            int l, r; cin >> l >> r;
            cout << fenwick.rsq(l, r) << "\n";
        }
    }
    
    return 0;
}
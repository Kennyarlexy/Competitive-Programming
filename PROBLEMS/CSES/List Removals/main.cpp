#include <bits/stdc++.h>
#define ll long long
#define LSOne(x) ((x) & (-x))
using namespace std;

int A[200005];

struct Fenwick {
    vector<int> ft;
    int N;
    Fenwick(int N) : ft(N+5) {
        this->N = N;
    };

    void update(int i, int v) {
        while (i <= N) {
            ft[i] += v;
            i += LSOne(i);
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += ft[i];
            i -= LSOne(i);
        }
        return res;
    }
};

int f(int x, int n, Fenwick &tree) {
    int y = n+1;
    for (int step = n; step > 0; step /= 2) {
        while (y - step >= 1 && (y - step) - tree.query(y-step) >= x) y -= step;
    }

    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    auto tree = Fenwick(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int y = f(x, n, tree);
        cout << A[y] << " ";
        tree.update(y, 1);
    }
    cout << "\n";
    
    return 0;
}
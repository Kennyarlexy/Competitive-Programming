#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

struct Custom {
    ll a, b, r1;
};

struct Fenwick {
    vector<ll> ft;
    int size = size;

    Fenwick(int size) : ft(size+5) {this->size = size;}

    ll sum(int i) {
        ll sum = 0;
        while (i > 0) {
            sum += ft[i];
            i -= ((i) & (-i));
        }
        return sum;
    }

    ll sum(int i, int j) {
        return sum(j) - sum(i-1);
    }

    void add(int i, int v) {
        while (i < size) {
            ft[i] += v;
            i += ((i) & (-i));
        }
    }
};

Custom C[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            C[i] = {a, b, 0};
        }

        sort(C+1, C+n+1, [] (Custom& A, Custom& B) {
            return A.a > B.a;
        });

        for (int i = 1; i <= n; i++) {
            C[i].r1 = i;
        }

        sort(C+1, C+n+1, [] (Custom& A, Custom& B) {
            return A.b > B.b;
        });

        Fenwick ft(n+5);
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            // basically how many people are still in front of you
            ll rank = C[i].r1 - ft.sum(C[i].r1) - 1;
            ans += rank;
            ft.add(C[i].r1, 1);
        }
        
        cout << ans << "\n";
    }

    
    return 0;
}
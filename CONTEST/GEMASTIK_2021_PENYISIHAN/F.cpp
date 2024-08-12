#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

ll A = 954934751, B = 966416447; // hash param
ll A_exp[200005];

struct Fenwick {
    vector<ll> ft;
    int size;

    Fenwick(const string &s, int len) : ft(len+5) {
        size = len+1;

        for (int i = 0, j = 1; i < len; i++, j++) {
            ft[j] += s[i];

            int k = j + LSOne(j);
            if (k < size) ft[k] = (ft[k] + ft[j]*A_exp[k-j]) % B;
        }
    }

    ll hash_val(int i) {
        // assuming i is compatible with ft
        ll hv = 0;
        int j = i;
        while (j > 0) {
            hv = (hv + ft[j]*A_exp[i-j]) % B;
            j -= LSOne(j);
        }

        return hv;
    }

    ll hash_val(int i, int j) {
        // assuming i and j is compatible
        ll hv_1 = hash_val(i-1);
        ll hv_2 = hash_val(j);
        
        ll hv_3 = (hv_2 - hv_1*A_exp[j-(i-1)]) % B;
        if (hv_3 < 0) hv_3 += B;

        return hv_3;
    }

    void update(int i, ll d) {
        // assuming i is compatible
        int j = i;
        ft[j] += d;
        if (ft[j] < 0) ft[j] += B;
        while (j + LSOne(j) < size) {
            j += LSOne(j);
            ft[j] = (ft[j] + d*A_exp[j-i]) % B;
            if (ft[j] < 0) ft[j] += B;
        }
    }
};

void solve(int a, int b, Fenwick &ft1, Fenwick &ft2, int N) {
    int k = 0;
    a++, b++;
    for (int step = b-a+1; step > 0; step /= 2) {
        while (a + k+step-1 <= b && ft1.hash_val(a, a + k+step-1) == ft2.hash_val(N-b+1, N-b+1 + k+step-1)) {
            k += step;
        }
    }

    cout << k << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;

    int N = s.length();
    A_exp[0] = 1;
    for (int i = 1; i <= N; i++) {
        A_exp[i] = A_exp[i-1]*A % B;
    }

    Fenwick ft1(s, N);

    reverse(s.begin(), s.end());
    Fenwick ft2(s, N);
    reverse(s.begin(), s.end());

    int Q; cin >> Q;

    for (int q = 1; q <= Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int x; char c;
            cin >> x >> c;
            // remember to offset index
            ll d = c - s[x];
            // cout << "d = " << d << "\n";
            ft1.update(x+1, d);
            ft2.update(N-x, d);
            s[x] = c;
            // cout << s << "\n";
        } else {
            int a, b;
            cin >> a >> b;
            // remember to offset index
            solve(a, b, ft1, ft2, N);
        }
    }
    
    return 0;
}


/*
aaaaaaaaa
3
0 0 8
1 4 b
0 0 8

aaacbacdcdbcaaa
1
0 0 14

aaacbacdcdbaaaa
1
0 0 14


a
3
0 0 0
1 0 z
0 0 0
*/
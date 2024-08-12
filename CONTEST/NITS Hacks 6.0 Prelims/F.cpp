#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
using namespace std;

string B[100005];
int C[100005];
bitset<100005> A[15]; // A[color][j] -> toy ke j

// A[0] = 11010011 // feature ke 0
// A[1] = 10001000 // feature ke 1
// A[2] = 10100000
//        ---------- or
//        11111011 -> berarti yang mirip ada 
// berapa banyak yang punya 0, 1, dan 2 -> A[0] | A[1] | A[2]
/*
    itung jumlah set yg punya x & y & z & ... in O(1)
                             pop_count(A[x] & A[y] & A[z] & ...).count
*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) {
        cin >> B[i]; 
    }

    for (ll i = 1; i <= n; i++) {
        cin >> C[i];
    }

    ll ans = 0;
    bitset<100005> BS;
    for (ll i = 1; i <= n; i++) {
        BS.reset();
        for (auto ch : B[i]) {
            BS |= A[ch-'0'];
        }

        // cout << "step 1 -> on = " << BS.count() << "\n";

        BS |= A[C[i]+10]; // set yang punya 1 kemiripan atau lebih

        ll add = i-1 - BS.count(); // count the member of set in O(1)
        // cout << "step 2 -> on = " << BS.count() << "\n";
        ans += add;
        // cout << "add = " << add << '\n';

        for (auto ch : B[i]) {
            A[ch-'0'][i] = 1;
        //    ^ featture
        //            ^ i-th toy has this feature
        //                  ^ set to true
        }

        A[C[i]+10][i] = 1;

        /*
        Tinggal substract yg 22ny aj
        color + feature - (color&&feature)
        
        */
    }

    cout << ans << "\n";
    
    return 0;
}


/*
2
1 2
1 1 // 0

2
1 2
1 2 // 1
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L, W, A; cin >> L >> W >> A;

    // bool ans = false;
    // while (L*W >= A) {
    //     int _A = A;
    //     while (L*W > _A) _A *= 2;
    //     if (L*W == _A) {
    //         ans = true;
    //         break;
    //     }
    //     A *= 2;
    // }

    // if (ans) cout << "YA\n";
    // else cout << "TIDAK\n";
        
    while (L*W > A) A *= 2;
    if (L*W == A) cout << "YA\n";
    else cout << "TIDAK\n";
    
    return 0;
}
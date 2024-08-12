#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool A[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Q; cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[x] = true;
    }

    for (int q = 1; q <= Q; q++) {
        int x; cin >> x;
        if (A[x]) cout << "ada\n";
        else cout << "tidak ada\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    
    ll cnt = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N-i; j++) {
            int k = N-i-j;
            if (i+j+k == N) cnt++;
        }
    }

    cout << cnt << "\n";
    
    return 0;
}
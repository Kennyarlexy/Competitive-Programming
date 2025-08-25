#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll A[100005];
int N, K; 

bool f(ll x) {
    ll sum = 0;
    ll cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (sum + A[i] > x) {
// cout << sum + A[i] << " > " << x << "\n";
            cnt++;
            sum = 0;
        }
        sum += A[i];
    }
    if (sum > x) {
// cout << sum << " > " << x << "\n";
        cnt++;
    }
    return cnt <= K;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    ll mx = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }

    // f(8);
    
    ll x = 1e14;
    for (ll step = x; step > 0; step /= 2) {
        while (x - step >= mx && f(x-step)) x -= step;
    }

    cout << x << "\n";

    return 0;
}
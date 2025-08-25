#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

ll A[100005];
ll B[100005];
int N, H, W;

bool f(int i) {
    for (int j = 1; j <= i; j++) {
        B[j] = A[j];
    }

    sort(B+1, B+i+1, greater<ll>());
    ll X = 0;
    for (int j = 1; j <= i; j+=W) {
        X += B[j];
        if (X > H) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H >> W;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int i = 0;
    for (int step = N; step > 0; step/=2) {
        while (i + step <= N && f(i + step)) {
            i += step;
        }
    }

    cout << i << "\n";
    
    return 0;
}
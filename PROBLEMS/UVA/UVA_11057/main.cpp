#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    while (cin >> N) {
        for (int i = 1; i <= N; i++) cin >> A[i];
        ll M; cin >> M;

        sort(A + 1, A + N + 1);
        ll x, y;
        for (int i = 1; i < N; i++) {
            int j = i+1;
            for (int step = N-j; step > 0; step /= 2) {
                while (j + step <= N && A[i] + A[j+step] <= M) j += step;
            }

            if (A[i] + A[j] == M) {
                x = A[i];
                y = A[j];
            }
        }

        cout << "Peter should buy books whose prices are " << x << " and " << y << ".\n\n";
    }
    
    return 0;
}
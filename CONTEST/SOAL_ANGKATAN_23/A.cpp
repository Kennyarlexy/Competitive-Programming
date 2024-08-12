#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double N; cin >> N;
    double U, H; cin >> U >> H;

    double X = 0;
    double Y = 0;
    int k = 0;
    while (X < N) {
        k++;
        X += U;

        if (k % 7 == 0) {
            Y += H/4;
            X += (H/4 - 30);
        }
    }

    cout << k << " hari\n";
    if (Y == 0) cout << "0\n";
    else cout << fixed << setprecision(2) << Y << " dolar\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }

        int x = 0, y = 0, z = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] <= 40) x++;
            else if (A[i] <= 60) y++;
            else z++;
        }

        cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}
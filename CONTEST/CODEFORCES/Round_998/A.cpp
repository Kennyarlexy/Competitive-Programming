#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int A[105];
int check() {
    int cnt = 0;
    for (int i = 1; i <= 3; i++) {
        if (A[i] + A[i+1] == A[i+2]) cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> A[1] >> A[2] >> A[4] >> A[5];

        vector<int> V = {A[5] - A[4], A[4] - A[2], A[2] - A[1]};

        int mx = 0;
        for (int i = 0; i < 3; i++) {
            A[3] = V[i];
            mx = max(mx, check());
        }

        cout << mx << "\n";
    }
    
    return 0;
}
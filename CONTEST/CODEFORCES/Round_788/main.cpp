#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int arr[100005];

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int cond_1 = 0, cond_2 = 0;
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] > arr[i-1] && arr[i] > arr[i+1]) possible = false;
            if (i < n - 1) {
                if (arr[i] > 0 && arr[i] > arr[i+1]) {
                    cond_1++;
                    continue;
                }
            }
            if (i > 0) {
                if (arr[i] < 0 && arr[i] < arr[i-1]) {
                    cond_2++;
                    continue;
                }
            }
        }
        if (cond_1 == cond_2 && possible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
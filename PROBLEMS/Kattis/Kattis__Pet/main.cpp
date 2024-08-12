#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int mx = INT_MIN, k;
    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j = 1; j <= 4; j++) {
            int x; cin >> x;
            sum += x;
        }

        if (sum > mx) {
            mx = sum;
            k = i;
        }
    }

    cout << k << " " << mx << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int init = 5050;
        for (int i = 1; i <= 100; i++) {
            cout << i << " ";
        }
        cout << endl;

        ll num[100];
        ll subtotal = 0;
        for (int i = 0; i < 100; i++) {
            cin >> num[i];
            subtotal += num[i];
        }

        sort(num, num + 100);
        ll target = (5050 + subtotal) / 2;
        ll current = 0;
        for (int i = 99; i >= 0; i--) {
            if (current + 5050 <= target) continue;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int arr[200005];
int arrn[200005];

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n, greater<int> ());
        int left = 0, right = n-1;
        for (int i = 0; i < n; i++) {
            int cur = (i % 2 == 0 ? left++ : right--);
            arrn[cur] = arr[i];
        }

        int k1 = 1;
        for (int i = 1; i < n; i++) {
            if (arrn[i-1] > arrn[i]) k1++;
            else if (arrn[i-1] < arrn[i])break;
        }

        int k2 = 1;
        for (int i = n-2; i >= 0; i--) {
            if (arrn[i] < arrn[i+1]) k2++;
            else if (arrn[i] > arrn[i+1])break;
        }

        // cout << k1 << " " << k2 << "\n\n";
        // for (int i = 0; i < n; i++) {
        //     cout << arrn[i] << " ";
        // }
        // cout << "\n";

        int result = min(k1, k2);
        cout << result << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[1000001];

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        fill(arr, arr + 1000001, 0);
        int N; cin >> N;
        for (int i = 1; i <= N; i++) {
            int d; cin >> d;
            arr[d]++;
        }

        int current = 0;
        for (int d = 4; d <= 1000000; d++) {
            current += fmin(d-current, arr[d]);
        }
        cout << "Case #" << t << ": " << current << "\n";
    }

    return 0;
}
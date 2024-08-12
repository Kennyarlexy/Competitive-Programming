#include <bits/stdc++.h>
using namespace std;

int A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q; cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int q = 1; q <= Q; q++) {
        int X; cin >> X;
        int R = -1, L = 0;
        int sum = 0;
        cout << "Case #" << q << ": ";
        bool OK = false;
        while (R + 1 < N) {
            sum += A[++R];
            while (sum < X && R + 1 < N) sum += A[++R];
            while (sum > X && L < R) sum -= A[L++];
            if (sum == X) {
                cout << L << " " << R << "\n";
                OK = true;
                break;
            }
        }

        if (!OK) cout << "-1\n";
    }
    
    return 0;
}
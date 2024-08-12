#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll A[200005], B[200005];

struct custom {
    ll sum, A, B;
};

custom C[200005];

bool cmp(custom A, custom B) {
    return A.sum > B.sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> B[i];
        }

        for (int i = 1; i <= n; i++) {
            C[i] = {A[i] + B[i], A[i], B[i]};
        }

        sort(C+1, C+n+1, cmp);
        ll A = 0, B = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                C[i].A -= 1;
                C[i].B = 0;
            } else {
                C[i].A = 0;
                C[i].B -= 1;
            }

            A += C[i].A;
            B += C[i].B;
        }

        cout << A - B << "\n";
    }
    
    return 0;
}
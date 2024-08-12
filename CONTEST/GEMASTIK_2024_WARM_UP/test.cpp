#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 1000; i++) {
        A[i] = i;
        for (int j = 2; j <= 290000; j++) {
            A[j] += (A[j-1] + j*5) % 1000000007;
        }
    }

    int N; cin >> N;
    map<int, int> MP;
    int mx = INT_MIN, id_mx = -1, mn = INT_MAX, id_mn = -1;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        MP[A[i]]++;
        if (A[i] > mx) {
            mx = A[i];
            id_mx = i;
        }

        if (A[i] < mn) {
            mn = A[i];
            id_mn = i;
        }
    }

    if (mx == mn) cout << "SESUAI\n";
    else {
        if (MP[mn] == 1 && MP[mx] == 1 && (mx-mn) % 2 == 0 && MP.size() <= 3) {
            cout << (mx-mn) / 2 << " " << id_mx << " " << id_mn << "\n";
        } else {
            cout << "TIDAK SESUAI\n";
        }
    }
    
    return 0;
}
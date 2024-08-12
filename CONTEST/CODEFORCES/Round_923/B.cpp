#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define LSOne(x) ((x) & (-x))
using namespace std;

int A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (A[i] == 0) A[i] = -1;
        }   

        char ch = 'a';
        for (int i = 1; i <= n; i++) {
            if (A[i] == -1) {
                cout << ch;
                ch++;
            } else {
                cout << 'a';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
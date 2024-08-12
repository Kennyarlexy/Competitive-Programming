#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

string A, B;
int C[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m; cin >> n >> m;
        
        cin >> A;

        for (int i = 0; i < m; i++) {
            cin >> C[i];
        }

        cin >> B;

        sort(B.begin(), B.end());
        sort(C, C+m);

        A[C[0]-1] = B[0];
        int j = 1;
        for (int i = 1; i < m; i++) {
            if (C[i] != C[i-1]) {
                A[C[i]-1] = B[j];
                j++;
            }
        }
        cout << A << "\n";
    }
    
    return 0;
}
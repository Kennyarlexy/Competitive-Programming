#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<bool> A(n+5);
        string a, b; cin >> a >> b;

        if (n == 2) {
            cout << "YES\n";
            continue;
        }
        
        for (int i = n-2; i >= 0; i-=2) {
            if (b[i] == '<') break;
            A[i] = true;
        }

        bool g = false;
        for (int i = 1; i < n-2; i+=2) {
            if (a[i] == '<') break;
            if (A[i+1]) {
                g = true;
                break;
            }
        }

        cout << (g || A[0] ? "YES":"NO") << "\n";
    }
    
    return 0;
}

/*
1
10
>>>>><>>><
>><<><><><

1
4
><><
><><
*/




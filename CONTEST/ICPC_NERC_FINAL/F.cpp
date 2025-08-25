#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

char A[200005], B[200005];;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        for (int i = 1; i <= n; i++) cin >> B[i];

        for (int i = 1; i <= n; i++) {
            if (A[i] == '.') {
                if (B[i] != '.') continue;
                if (i > 1 && A[i-1] == '.') continue;
                if (i < n && A[i+1] == '.') continue;

                A[i] = B[i] = '#';
            }
        }

        for (int i = 1; i <= n; i++) {
            if (B[i] == '.') {
                if (A[i] != '.') continue;
                if (i > 1 && B[i-1] == '.') continue;
                if (i < n && B[i+1] == '.') continue;

                A[i] = B[i] = '#';
            }   
        }

        for (int i = 1; i + 1 <= n; i++) {
            if (A[i] == '.' && A[i+1] == '.') {
                A[i] = '^'; A[i+1] = '$';
            }

            if (B[i] == '.' && B[i+1] == '.') {
                B[i] = '^'; B[i+1] = '$';
            }
        }

// for (int i = 1; i <= n; i++) cout << A[i];
// cout << "\n";
// for (int i = 1; i <= n; i++) cout << B[i];
// cout << "\n";

        bool none = false;
        int f1 = -1, f2 = -1;
        for (int i = 1; i <= n; i++) {
            if (A[i] == '.') f1 = i;
            if (B[i] == '.') f2 = i;

            int j = i;
            if (f1 != -1) {
                while (f2 == -1 && j <= n && B[j] != '#') {
                    if (B[j]  == '.') f2 = j;
                    j++;
                }    
            } else if (f2 != -1) {
                while (f1 == -1 && j <= n && A[j] != '#') {
                    if (A[j] == '.') f1 = j;
                    j++;
                }
            }

            if (f1 != -1) {
                if (f2 == -1 || (f2 - f1) % 2 != 0) {
                    none = true;
                    break;
                }

            } else if (f2 != -1) {
                if (f1 == -1 || (f1 - f2) % 2 != 0) {
                    none = true;
                    break;
                }
            }

            i = j;
            f1 = f2 = -1;
        }

        bool unique = true;
        for (int i = 1; i + 1 <= n; i++) {
            if (A[i] == '^' && B[i] == '^') {
                unique = false;
                break;
            }
        }

        if (none) {
            cout << "None\n";
            continue;
        }

        if (unique) {
            cout << "Unique\n";
        } else {
            cout << "Multiple\n";
        }
    }
    
    return 0;
}


/*
#^$.#.
#^$^$.

#^$.###
##^$^$.

#^$o###
##^$^$o

1
7
#...###
##.....
*/



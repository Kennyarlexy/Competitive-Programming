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
        string s; cin >> s;

        if (n == 1) cout << s << "\n";
        else if (n == 2) {
            int ans = (s[0] - '0')*10 + s[1] - '0';
            cout << ans << "\n";
        } else {
            int mn = INT_MAX;
            for (int i = 1; i < n; i++) {
                int X = (s[i-1] - '0')*10 + s[i] - '0';
                bool g = X == 1;
                bool f = false;
                bool h = false;
                for (int j = 0; j < n; j++) {
                    if (j == i-1 || j == i || s[j] == '1') continue;
                    if (s[j] == '0') f = true;
                    h = true;                    
                    X += s[j] - '0';
                }

                if (f) X = 0;
                else if (g && h) X--;
                mn = min(mn, X);
            }

            cout << mn << "\n";
        }
    }
    
    return 0;
}

/*
5
3
115
4
1115
5
11115
5
11151
5
11511

4
2
10
2
01
2
00
2
11

1
2
59

4
3
111
4
1111
5
51155
3
101

2
4
1011
4
1019

1
5
51111
*/
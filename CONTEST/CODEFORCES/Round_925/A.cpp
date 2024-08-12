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
        string ans = "aaa";
        n -= 3;
        int i = 2;
        while (n > 0) {
            ans[i]++;
            n--;
            if (ans[i] == 'z') i--;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
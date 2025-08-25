#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bool A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[x] = true;
    }

    vector<string> ans;

    for (int i = 1; i <= 1000; i++) {
        if (!A[i]) continue;
        int j = i;
        while (j+1 <= 1000 && A[j+1]) j++;
        if (i == j) ans.push_back(to_string(i));
        else {
            ans.push_back(to_string(i) + "-" + to_string(j));
        }
        i = j;
    }

    int m = ans.size();
    for (int i = 0; i < m; i++) {
        cout << ans[i];
        if (i < m-1) cout << ",";
    }
    cout << "\n";
    
    return 0;
}
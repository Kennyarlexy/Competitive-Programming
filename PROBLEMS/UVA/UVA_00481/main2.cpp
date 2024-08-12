#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[100005];
int p[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    while (cin >> A[n+1]) n++;

    vector<int> V, id;
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
        if (k == V.size()) {
            V.push_back(A[i]);
            id.push_back(i);
        } else {
            V[k] = A[i];
            id[k] = i;
        }
        
        p[i] = (k == 0) ? -1 : id[k-1];
    }

    int m = V.size();
    cout << m << "\n-\n";
    
    int j = id.back();
    vector<int> ans;
    while (j != -1) {
        ans.push_back(A[j]);
        j = p[j];
    }

    for (int i = m-1; i >= 0; i--) cout << ans[i] << "\n";
    
    return 0;
}
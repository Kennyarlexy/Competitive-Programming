#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

string A[105];
int B[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    map<int, int> MP;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
        MP[B[i]]++;
    }

    vector<string> ans;
    for (int i = 1; i <= n; i++) {
        if (MP[B[i]] == 1) ans.push_back(A[i]);
    }

    sort(ans.begin(), ans.end());

    int k = ans.size();
    cout << k << "\n";
    if (k == 0) {
        cout << "Seluruh siswa mencontek!\n";
    } else if (k == n) {
        cout << "Semua siswa mengerjakan dengan jujur!\n";
    }

    for (auto an : ans) {
        cout << an << "\n";
    }
    
    return 0;
}
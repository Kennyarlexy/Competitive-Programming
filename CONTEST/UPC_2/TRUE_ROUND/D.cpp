#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

pair<int, int> O[5005];
string S[5005];

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.first == B.first) {
        return (A.second < B.second);
    }
    return A.first > B.first;
}

int main() {
    fast_io();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        int f; cin >> f;
        O[i-1] = {f, i};
    }

    sort(O, O + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << S[O[i].second] << " " << O[i].first << "\n";
    }

    return 0;
}
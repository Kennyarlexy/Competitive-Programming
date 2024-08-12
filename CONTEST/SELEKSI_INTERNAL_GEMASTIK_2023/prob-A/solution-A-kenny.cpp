#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    vector<int> ganjil, genap;
    for (int i = 1; i <= 100000; i++) {
        if (cnt[i] == 1) {
            if (i % 2 == 0) genap.push_back(i);
            else ganjil.push_back(i);
        }
    }

    int j = 0;
    while (j < ganjil.size() && j < genap.size()) {
        cout << ganjil[j] << " " << genap[j] << " ";
        j++;
    }
    while (j < ganjil.size()) cout << ganjil[j++] << " ";
    while (j < genap.size()) cout << genap[j++] << " ";
    cout << "\n";

    
    return 0;
}
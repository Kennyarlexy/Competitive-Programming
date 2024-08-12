#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<char> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (ll i = 0; i < 256; i++) {
        if (isalpha(i)) A.push_back(i);
    }
    
    bool flag = false;
    ll n;
    while (cin >> n) {
        if (flag) cout << "\n";
        cout << 2 << " " << n << " " << n << "\n";

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cout << A[i];
            }
            cout << "\n";
        }
        cout << "\n";
        
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cout << A[j];
            }
            cout << "\n";
        }
        flag = true;
    }
    
    return 0;
}
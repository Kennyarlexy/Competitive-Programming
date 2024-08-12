#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<ll> S;
    auto itr = S.lower_bound(-1);
    cout << (itr == S.begin()) << "\n";
    cout << (S.begin() == S.end()) << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;


vector<ll> A;
//AC!!!!!!!!!!!!
//probably the best recursive version of this problem
//returns the size of the doll or returns -1 when a bad design detected
ll f(ll &i) {
    ll sum = 0;
    ll open = -A[i];
    while (++i < A.size() && A[i] < 0) {
        ll child = f(i);
        if (child == -1) {
            sum = -1;
            break;
        }
        sum += child;
    }

    if (sum != -1 && i < A.size() && A[i] == open && sum < open) return A[i];
    else return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        stringstream SS(line);
        A = {};
        ll a;
        while (SS >> a) A.push_back(a);
        ll i = 0;
        if (f(i) != -1) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
    }
    
    return 0;
}
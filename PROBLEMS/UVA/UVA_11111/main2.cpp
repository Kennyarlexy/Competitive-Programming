#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

vector<ll> A;
//AC!!!!!!!!!!!!1
//returns {size of child, good design or not}
pair<ll, bool> f(ll &i) {
    ll sum = 0;
    ll open = -A[i];
    pair<ll, bool> child; child.se = true;
    while (++i < A.size() && A[i] < 0 && child.se) {
        child = f(i);
        sum += child.fi;
    }

    if (child.se && i < A.size() && A[i] == open && sum < open) return {A[i], true};
    else return {A[i], false};
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
        if (f(i).se) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
    }
    
    return 0;
}
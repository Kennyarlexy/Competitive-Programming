#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

vector<ll> A;
// WA!!!!!!!!!!!!!!!!!
//even though it's a more familiar recursive form, this one feels kinda bad to implement

//returns {the size of the current doll or -1 when bad design detected, whether or not we should continue to check the next child doll}
pair<ll, bool> f(ll &i) {
    if (i == A.size() || A[i] > 0) {
        if (i == 0) return {-1, false};
        else return {0, false};
    }

    ll sum = 0;
    ll open = -A[i];
    while (true) {
        auto child = f(++i);
        if (!child.se) break;
        if (child.fi == -1) {
            sum = -1;
            break;
        }
        sum += child.fi;
    }

    if (sum == -1 || sum >= open || i == A.size() || A[i] != open) return {-1, false};

    return {A[i], true};
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
        if (f(i).fi != -1) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
    }
    
    return 0;
}
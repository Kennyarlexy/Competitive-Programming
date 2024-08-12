#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Order {
    ll a;
    ll b;
    ll c;
};

bool cmp(Order A, Order B) {
    return A.c < B.c;
}

int main() {
    fast_io();
    //use ll when possible!
    
    for (ll b = 2; b <= 10; b++) {
        ll a = b-1;
        cout << b*b - a*a << "\n";
    }

    cout << "--------\n";

    for (ll b = 3; b <= 20; b++) {
        ll a = b-2;
        cout << b*b - a*a << "\n";
    }

    cout << "--------\n";

    for (ll b = 4; b <= 30; b++) {
        ll a = b-3;
        cout << b*b - a*a << "\n";
    }

    cout << "--------\n";

    for (ll b = 5; b <= 30; b++) {
        ll a = b-4;
        cout << b*b - a*a << "\n";
    }
    // vector<Order> res;

    // for (ll i = 2; i <= 20; i++) {
    //     for (ll j = i-1; j >= 1; j--) {
    //         res.push_back({j, i, i*i - j*j});
    //     }
    // }

    // sort(res.begin(), res.end(), cmp);

    // for (auto& [a, b, c] : res) {
    //     cout << a << "\t" << b << "\t -> " << c << "\n";
    // }

    return 0;
}
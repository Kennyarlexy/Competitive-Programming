#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

bool cmp(pair<string, ll> &A, pair<string, ll> &B) {
    if (A.se == B.se) {
        return A.fi < B.fi;
    }
    return A.se < B.se;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<string, ll>> res; res.reserve(105);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        cin.ignore(1000, '\n');
        string binder; getline(cin, binder);
        ll m, n, b; cin >> m >> n >> b;

        unordered_map<string, ll> P; P.reserve(m);
        for (ll i = 1; i <= m; i++) {
            string I; ll p;
            cin >> I >> p;
            P[I] = p;
        }

        res.resize(0);
        for (ll i = 1; i <= n; i++) {
            cin.ignore(1000, '\n');
            string title; getline(cin, title);
            ll k; cin >> k;

            ll cost = 0;
            for (ll j = 1; j <= k; j++) {
                string I; ll x;
                cin >> I >> x;
                cost += P[I]*x;
            }

            if (cost <= b) {
                res.push_back({title, cost});
            }
        }

        for (auto& ch : binder) ch = toupper(ch);
        cout << binder << "\n";
        if (res.size() == 0) {
            cout << "Too expensive!\n";
        } else {
            sort(res.begin(), res.end(), cmp);
            for (auto d : res) {
                cout << d.fi << "\n";
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
2
My Favourite Cheesecake
8 3 100
sugar 4
water 0
lemonjuice 3
creamcheese 20
vanilla 5
egg 5
cream 10
strawberry 5
Strawberry Whipped Cream
2
cream 5
strawberry 3
Scrumptious Caramel Topping
3
sugar 6
water 3
lemonjuice 1
Secret Cheesecake Base
5
creamcheese 3
sugar 5
vanilla 1
egg 6
cream 1
Million Dollar Cakes
3 1 999999
costlyflour 500
gold 4500
diamond 5000
Display Cake - Do Not Eat!
3
costlyflour 100
gold 100
diamond 100
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct state {
    char mode;
    ll owner, cnt;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        unordered_map<ll, state> Item;
        unordered_set<ll> blocked;
        char mode;
        while (true) {
            cin >> mode;
            if (mode == '#') break;
            ll trid, item; cin >> trid >> item;
            if (blocked.count(trid)) {
                cout << "IGNORED\n";
            } else {
                if (Item.count(item)) {
                    if (Item[item].mode == 'S') {
                        if (Item[item].owner != trid) {
                            Item[item].cnt++;
                        }
                        if (mode == 'X') {
                            if (Item[item].cnt == 1) {
                                Item[item].mode = 'X';
                                cout << "GRANTED\n";
                            } else {
                                cout << "DENIED\n";
                                blocked.insert(trid);
                            }
                        } else {
                            cout << "GRANTED\n";
                        }
                    } else {
                        if (Item[item].owner == trid) {
                            cout << "GRANTED\n";
                        } else {
                            cout << "DENIED\n";
                            blocked.insert(trid);
                        }
                    }
                } else {
                    cout << "GRANTED\n";
                    Item[item] = {mode, trid, 1};
                }
            }
        }

        if (t < T) cout << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(string w) {
    ll weight = 0;
    
    for (auto& d : w) {
        bool flag = false;
        for (ll i = 7; i >= 0; i--) {
            if (d & (1LL << i)) {
                flag = true;
                weight += 500;
            } else if (flag) {
                weight += 250;
            }
        }
    }

    return weight;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string w1, w2;
        ll h1, h2;
        
        for (ll r = 1; r <= 8; r++) {
            for (ll c = 1; c <= 18; c++) {
                char a; cin >> a;
                if (isalpha(a)) {
                    if (c <= 9) {
                        w1.push_back(a);
                    } else {
                        w2.push_back(a);
                    }
                } else if (a == '_') {
                    if (c <= 9) h1 = r;
                    else h2 = r;
                }
            }
        }

        ll _w1 = f(w1);
        ll _w2 = f(w2);
        cout << "Case " << t << ":\n";
        if ((h1 == h2) == (_w1 == _w2) && (h1 > h2) == (_w1 > _w2)) {
            cout << "The figure is correct.\n";
        } else {
            w1.resize(6, '.'); w2.resize(6, '.');
            if (_w1 > _w2) {
                cout << "........||.../\\...\n";
                cout << "........||../..\\..\n";
                cout << ".../\\...||./....\\.\n";
                cout << "../..\\..||/" << w2 << "\\\n";
                cout << "./....\\.||\\______/\n";
                cout << "/" << w1 << "\\||........\n";
                cout << "\\______/||........\n";
            } else if (_w1 < _w2) {
                cout << ".../\\...||........\n";
                cout << "../..\\..||........\n";
                cout << "./....\\.||.../\\...\n";
                cout << "/" << w1 << "\\||../..\\..\n";
                cout << "\\______/||./....\\.\n";
                cout << "........||/" << w2 << "\\\n";
                cout << "........||\\______/\n";
            } else {
                cout << "........||........\n";
                cout << ".../\\...||.../\\...\n";
                cout << "../..\\..||../..\\..\n";
                cout << "./....\\.||./....\\.\n";
                cout << "/" << w1 << "\\||/" << w2 << "\\\n";
                cout << "\\______/||\\______/\n";
                cout << "........||........\n";
            }
        }

    }
    
    return 0;
}

/*
4
........||.../\...
........||../..\..
.../\...||./....\.
../..\..||/G.....\
./....\.||\______/
/YQYFU.\||........
\______/||........
------------------
.../\...||........
../..\..||........
./....\.||.../\...
/WCGQG.\||../..\..
\______/||./....\.
........||/OYA...\
........||\______/
------------------
.../\...||........
../..\..||........
./....\.||.../\...
/A.....\||../..\..
\______/||./....\.
........||/A.....\
........||\______/
------------------
........||........
.../\...||.../\...
../..\..||../..\..
./....\.||./....\.
/NQ....\||/FG....\
\______/||\______/
........||........
------------------
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

//10 numbers with 5 segment each, contains type that are assigned to a number
ll seg[5][10] = {
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {3, 2, 2, 2, 3, 1, 1, 2, 3, 3},
    {0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {3, 2, 1, 2, 2, 2, 3, 2, 3, 2},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 1}
};

void outputH(ll size, ll n, ll _seg) {
    if (seg[_seg][n] == 0) {
        for (ll i = 1; i <= size+2; i++) {
            cout << " ";
        }
    } else {
        cout << " ";
        for (ll i = 1; i <= size; i++) {
            cout << "-";
        }
        cout << " ";
    }
}

void outputV(ll size, ll n, ll _seg) {
    if (seg[_seg][n] == 1) {
        cout << "|";
        for (ll i = 1; i <= size+1; i++) {
            cout << " ";
        }
    } else if (seg[_seg][n] == 2) {
        for (ll i = 1; i <= size+1; i++) {
            cout << " ";
        }
        cout << "|";
    } else {
        cout << "|";
        for (ll i = 1; i <= size; i++) {
            cout << " ";
        }
        cout << "|";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll size; string num;
    while (true) {
        cin >> size >> num;
        if (size == 0 && num == "0") break;

        ll len = num.length();
        for (ll _seg = 0; _seg < 5; _seg++) {
            if (_seg % 2 == 0) {
                for (ll i = 0; i < len; i++) {
                    outputH(size, num[i]-'0', _seg);
                    if (i < len-1) cout << " ";
                }
                cout << "\n";
            } else {
                for (ll r = 1; r <= size; r++) {
                    for (ll i = 0; i < len; i++) {
                        outputV(size, num[i]-'0', _seg);
                        if (i < len-1) cout << " ";              
                    }
                    cout << "\n";
                }
            }
        }
        cout << "\n";
    }
    
    return 0;
}
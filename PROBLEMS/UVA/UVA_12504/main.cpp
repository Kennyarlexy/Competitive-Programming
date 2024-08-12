#include <bits/stdc++.h>
#define ll long long
using namespace std;

void f(string &s, unordered_map<string, string> &dict, set<string> &all) {
    string t;
    for (auto& ch : s) {
        if (!isalpha(ch) && !isdigit(ch)) {
            t.push_back(' ');
        } else {
            t.push_back(ch);
        }
    }

    stringstream SS(t);
    while (!SS.eof()) {
        string key, val;
        SS >> key >> val;
        dict[key] = val;
        all.insert(key);
    }
}

void print(vector<string> &res) {
    cout << res[0];
    for (ll i = 1; i < res.size(); i++) {
        cout << "," << res[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string A, B; cin >> A >> B;
        unordered_map<string, string> dictA, dictB;
        set<string> all;
        f(A, dictA, all);
        f(B, dictB, all);

        vector<string> add, del, changed;
        for (auto& d : all) {
            if (dictA.count(d) && dictB.count(d)) {
                if (dictA[d] != dictB[d]) {
                    changed.push_back(d);
                }
            } else if (dictA.count(d)) {
                del.push_back(d);
            } else {
                add.push_back(d);
            }
        }

        if (add.empty() && del.empty() && changed.empty()) {
            cout << "No changes\n";
        }

        if (!add.empty()) {
            cout << "+";
            print(add);
        } 
        if (!del.empty()) {
            cout << "-";
            print(del);
        }
        if (!changed.empty()) {
            cout << "*";
            print(changed);
        }
        cout << "\n";
    }
    
    return 0;
}

/*
3
{a:3,b:4,c:10,f:6}
{a:3,c:5,d:10,ee:4}
{x:1,xyz:123456789123456789123456789}
{xyz:123456789123456789123456789,x:1}
{first:1,second:2,third:3}
{third:3,second:2}
*/
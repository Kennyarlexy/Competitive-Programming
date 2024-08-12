#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    stack<string> st;
    for (ll i = 1; i <= n; i++) {
        string cmd; cin >> cmd;
        if (cmd == "Sleep") {
            string s; cin >> s;
            st.push(s);
        } else if (cmd == "Kick") {
            if (!st.empty()) st.pop();
        } else {
            if (!st.empty()) cout << st.top() << "\n";
            else cout << "Not in a dream\n";
        }
    }
    
    return 0;
}

/*
20
Sleep Dom
Sleep Sakin
Test
Sleep Asif
Sleep Mushfiq
Test
Kick
Test
Sleep Shafi
Test
Kick
Test
Kick
Test
Kick
Test
Kick
Test
Kick
Test
*/
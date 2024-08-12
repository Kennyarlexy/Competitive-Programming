#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    cin.ignore(1000, '\n');
    for (ll i = 1; i <= n; i++) {
        string s; getline(cin, s);
        stack<char> st;
        bool OK = true;
        for (auto& ch : s) {
            if (ch == '(' || ch == '[') {
                st.push(ch);
            } else if (ch == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    OK = false;
                    break;
                }
            } else if (ch == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else {
                    OK = false;
                    break;
                }
            }
        }

        if (OK && st.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}
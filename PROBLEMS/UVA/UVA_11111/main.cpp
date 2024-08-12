#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        stringstream SS(line);
        ll a;
        stack<pair<ll, ll>> st;
        bool OK = true;
        while (SS >> a) {
            if (a < 0) {
                st.push({-a, 0});
            } else {
                if (!st.empty() && a == st.top().fi && st.top().se < st.top().fi) {
                    st.pop();
                    if (!st.empty()) {
                        auto top = st.top(); st.pop();
                        top.se += a;
                        st.push(top);
                    }
                } else {
                    OK = false;
                    break;
                }
            }
        }

        if (OK && st.empty()) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
    }
    
    return 0;
}
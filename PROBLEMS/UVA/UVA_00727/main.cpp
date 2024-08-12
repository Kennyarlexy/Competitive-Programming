#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<string, ll> MP = {
    {"*", 2},
    {"/", 2},
    {"+", 1},
    {"-", 1},
    {"(", 0}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T; cin >> T;
    cin.ignore(1000, '\n');
    string line;
    getline(cin, line);
    for (ll t = 1; t <= T; t++) {
        stack<string> st;
        while (getline(cin, line)) {
            if (line.empty()) break;

            if (isdigit(line[0])) {
                cout << line;
            } else if (line == "(") {
                st.push(line);
            } else if (line == ")") {
                while (!st.empty() && st.top() != "(") {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && MP[st.top()] >= MP[line]) {
                    cout << st.top();
                    st.pop();
                }
                st.push(line);
            }

        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
        if (t < T) cout << "\n";
    }
    
    return 0;
}

/*
3

(
3
+
2
)
*
5

(
3
+
2
)
*
5

1
+
3
*
4
/
5
*
6
-
2
*/
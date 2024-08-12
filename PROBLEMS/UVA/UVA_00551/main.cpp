#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s)) {
        stack<string> st;

        ll i = 0, pref = 0;
        bool OK = true;
        while (i < s.length()) {
            string b;
            if (i+1 < s.length()) {
                if (s[i] == '(' && s[i+1] == '*') {
                    b = "(*";
                } else if (s[i] == '*' && s[i+1] == ')') {
                    b = "*)";
                } else {
                    b = s[i];
                }
            } else {
                b = s[i];
            }

            if (b == ")" || b == "]" || b == "}" || b == ">" || b == "*)") {
                if (!st.empty() && st.top() == b) st.pop();
                else {
                    OK = false;
                    break;
                }
            } 
            else if (b == "(") st.push(")");
            else if (b == "[") st.push("]");
            else if (b == "{") st.push("}");
            else if (b == "<") st.push(">");
            else if (b == "(*") st.push("*)");

            pref++;
            i += b.length();
        }

        if (OK && st.empty()) cout << "YES\n";
        else cout << "NO " << pref+1 << "\n";
    }
    
    return 0;
}

/*
(*)
(**)
(***)
()()()
*****************
(***))
(((((()(()
*/
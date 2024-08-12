#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool f(vector<string> &A) {
    for (ll i = 0; i < A.size(); i++) {
        if (A[i] == "*") {
            ll a = stoll(A[i-1]), b = stoll(A[i+1]);
            ll res = a*b;
            A.erase(A.begin()+i, A.begin()+i+2);
            A[i-1] = to_string(res);
            return true;
        } else if (A[i] == "/") {
            ll a = stoll(A[i-1]), b = stoll(A[i+1]);
            ll res = a/b;
            A.erase(A.begin()+i, A.begin()+i+2);
            A[i-1] = to_string(res);
            return true;
        }
    }

    for (ll i = 0; i < A.size(); i++) {
        if (A[i] == "+") {
            ll a = stoll(A[i-1]), b = stoll(A[i+1]);
            ll res = a+b;
            A.erase(A.begin()+i, A.begin()+i+2);
            A[i-1] = to_string(res);
            return true;
        } else if (A[i] == "-") {
            ll a = stoll(A[i-1]), b = stoll(A[i+1]);
            ll res = a-b;
            A.erase(A.begin()+i, A.begin()+i+2);
            A[i-1] = to_string(res);
            return true;
        }
    }
    return false;
}

void print(vector<string> &A) {
    for (ll i = 0; i < A.size(); i++) {
        cout << A[i] << " \n"[i==A.size()-1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    bool first = true;
    while (getline(cin, line)) {
        string s;
        bool flag = false;
        for (ll i = 0; i < line.length(); i++) {
            char ch = line[i];
            if (isdigit(ch)) {
                s += ch;
                flag = false;
            } else if (ch != ' ') {
                if (i != 0 && !flag) {
                    s += " ";
                    s += ch;
                    s += " ";
                } else {
                    s += ch;
                }
                flag = true;
            }
        }

        stringstream SS(s);
        string t;
        vector<string> A;
        while (SS >> t) {
            A.push_back(t);
        }

        for (ll i = 0; i < A.size()-2; i+=2) {
            A[i] = to_string(stoll(A[i]));
        }
        
        if (!first) cout << "\n";
        print(A);
        while (f(A)) print(A);
        first = false;
    }
    
    return 0;
}

/*
15 -- 15 = x
15 -- 15 -- 15 = x
15 - -15 - -15 = x
15- -15- -15 = x
15 -+ 15 = x
15 -+ 15 -+ 15 = x
15 - +15 - +15 = x
15+ +15+ +15 = x
*/
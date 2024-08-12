#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    string infix = "4 * ( 1 + 2 * ( 9 / 3 ) - 5 )";
    map<string, ll> Presedence = {
        {"*", 2},
        {"/", 2},
        {"+", 1},
        {"-", 1},
        {"(", 0}
    };

    vector<string> A;
    stringstream SS(infix);
    string t;
    while (SS >> t) {
        A.push_back(t);
    }


    stack<string> Stack;
    vector<string> B;
    for (auto& d : A) {
        if (isdigit(d[0])) B.push_back(d);
        else if (d == "(") Stack.push(d);
        else if (d == ")") {
            while (Stack.top() != "(") {
                B.push_back(Stack.top()); Stack.pop();
            }
            Stack.pop();
        }
        else {
            while (!Stack.empty() && Presedence[Stack.top()] >= Presedence[d]) {
                B.push_back(Stack.top()); Stack.pop();
            }
            Stack.push(d);
        }
    }

    while (!Stack.empty()) {
        B.push_back(Stack.top()); Stack.pop();
    }

    for (auto& d : B) {
        cout << d << " ";
    }
    cout << "\n";

    stack<ll> Stack2;
    for (auto& d : B) {
        if (isdigit(d[0])) Stack2.push(stoll(d));
        else {
            ll B = Stack2.top(); Stack2.pop();
            ll A = Stack2.top(); Stack2.pop();
            if (d == "*") Stack2.push(A*B);
            else if (d == "/") Stack2.push(A/B);
            else if (d == "+") Stack2.push(A+B);
            else Stack2.push(A-B);
        }
    }

    cout << "res = " << Stack2.top() << "\n";
    
    return 0;
}
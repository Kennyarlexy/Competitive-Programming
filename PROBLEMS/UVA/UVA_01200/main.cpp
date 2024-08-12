#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string A, B;
        cin >> A;
        for (ll i = 0; i < A.length(); i++) {
            if (!isdigit(A[i]) && A[i] != 'x') B += " ";
            B += A[i];
            if (A[i] == '=') B += " ";
        }

        stringstream SS(B);
        string temp;
        ll coef = 0, c = 0;
        bool flag = false;
        while (SS >> temp) {
            if (temp == "=") {
                flag = true;
                continue;
            }   

            if (temp.back() == 'x') {
                ll _coef = 0;
                if (temp == "+x" || temp == "x") 
                    _coef = 1;
                else if (temp == "-x")
                    _coef = -1;
                else
                    _coef = stoll(temp.substr(0, temp.length()-1));

                if (flag) _coef = -_coef;
                coef += _coef;
            } else {
                ll _c = stoll(temp);
                if (!flag) _c = -_c;
                c += _c;
            }
        }

        if (coef == 0 && c == 0) {
            cout << "IDENTITY\n";
        } else if (coef == 0) {
            cout << "IMPOSSIBLE\n";
        } else {
            // both solutions work
            // if (c < 0 && coef > 0) {
            //     cout << (c-coef+1)/coef << "\n";
            // } else if (c > 0 && coef < 0) {
            //     cout << (c-coef-1)/coef << "\n";
            // } else {
            //     cout << c/coef << "\n";
            // }
            double res = floor((double) c / coef);
            if (res == -0) res = 0;
            cout << res << "\n";
        }
    }
    
    return 0;
}
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
    string A, B;
    while (getline(cin, A) && getline(cin, B)) {
        ll A1 = 0;
        for (auto& ch : A) {
            ch = tolower(ch);
            if (ch >= 'a' && ch <= 'z') A1 += ch - 'a' + 1;
        }

        while (A1 >= 10) {
            ll temp = 0;
            while (A1 > 0) {
                temp += A1 % 10;
                A1 /= 10;
            }
            A1 = temp;
        }
        
        ll B1 = 0;
        for (auto& ch : B) {
            ch = tolower(ch);
            if (ch >= 'a' && ch <= 'z') B1 += ch - 'a' + 1;
        }

        while (B1 >= 10) {
            ll temp = 0;
            while (B1 > 0) {
                temp += B1 % 10;
                B1 /= 10;
            }
            B1 = temp;
        }
        
        if (A1 > B1) swap(A1, B1);
        double ratio = (double) A1 / B1;
        cout << fixed << setprecision(2) << min(ratio, 1.0) * 100 << " %\n";
    }

    return 0;
}
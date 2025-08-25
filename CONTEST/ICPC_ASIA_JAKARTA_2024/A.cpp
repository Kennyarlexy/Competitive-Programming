#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = s.length();
    set<char> S1 = {'A', 'I', 'U', 'E', 'O'};
    int N = 0, G = 0, Y = 0, cons = 0, vow = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') N++;
        else if (s[i] == 'G') G++;
        else if (s[i] == 'Y') Y++;

        if (S1.count(s[i])) vow++;
        else cons++;
    }

    int mx = INT_MIN;
    for (int i = 0; i <= min(N, G); i++) {
        for (int j = 0; j <= Y; j++) {
            int NG = i;
            int _Y = j;

            int _vow = vow + _Y;
            int _cons = cons - 2*NG - _Y;
            
            int len = 0;
            int A = min(_vow, NG/2);
            len += 5*A;
            _vow -= A;

            if (NG % 2 == 1 && _vow == 1 && _cons == 1) {
                len += 4;
                vow--;
                cons--;
            }

            int B = min(_vow, _cons/2);
            len += 3*B;

            mx = max(mx, len);
        }
    }

    cout << mx << "\n";
    
    return 0;
}
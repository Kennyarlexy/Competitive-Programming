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
    int NG = min(N, G);
    for (int i = 0; i <= Y; i++) {
        int _vow = vow + i;
        int _NG = NG;
        int _cons = cons - i - 2*_NG;

// cout << _vow << " " << _cons << "\n";
        int len = 0;
        int port = 0;

        int A = min(_vow, _cons/2); // susun vowel 
        _vow -= A;
        _cons -= 2*A;
        len += 3*A;
        port += 2*A;

        if (_cons == 1) {
            len += 4;
            _NG--;
            _vow--;
            _cons--;
            port++;
        }
        
        int B = min(_vow, _NG);
        _vow -= B;
        _NG -= B;
        len += 3*B;

        int C = min(B, _NG);
        _NG -= C;
        len += 2*C;

        int D = min(port, _NG);
        _NG -= D;
        len += D;

        mx = max(mx, len);
    }

    cout << mx << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt = 0;

string seq;

void f(int i, int p, int n) {
    if (i > n) {
        if (1-p == 1) { //prev player
            cnt++;
            cout << setw(5) << cnt << " -> " << seq << "\n";
        }
        return;
    }

    seq.push_back((p == 1 ? '.' : '-'));
    f(i+1, 1-p, n);

    if (i+1 <= n) {
        seq.push_back((p == 1 ? '.' : '-'));
        f(i+2, 1-p, n);
        seq.pop_back();
    }

    seq.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    f(1, 1, n);
    f(1, 0, n);
    cout << cnt << "\n";
    
    return 0;
}
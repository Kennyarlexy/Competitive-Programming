#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int X, N; cin >> X >> N;

    int a = 0;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (x <= 3) X -= 2*x;
        else X -= 5*x;    

        if (X >= 0) a++;
    }

    if (a == N) cout << "MISSION ACCOMPLISHED!\n";
    else if (a == 0) cout << "MISSION FAILED!\n";
    else cout << "MISSION IN PROGRESS!\n";

    cout << a << " " << N-a << "\n";
    
    return 0;
}
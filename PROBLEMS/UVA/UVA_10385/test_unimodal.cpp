#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

pair<double, double> A[25];
double f(double r, double k, int n) {
    double X = r/A[n].fi + k/A[n].se;
    double Y = 1e9;
    for (int i = 1; i < n; i++) {
        Y = min(Y, r/A[i].fi + k/A[i].se);
    }

    return (Y - X) * 3600;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x; cin >> x;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].fi >> A[i].se;
    }

    for (double r = 0.01; r <= x; r += 0.01) {
        cout << "for r = " << r << ", win by " << f(r, x-r, n) << " seconds\n";
    }
    
    return 0;
}

/*
100
3
113.0 40.0
231.0 40.0
174.0 75.0
*/
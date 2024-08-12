#include <bits/stdc++.h>
#define ll long long

using namespace std;

int A[200005], B[200005], C[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x = -0.5;
    double y = ceil(x);
    cout << y << "\n";
    cout << (y == 0) << "\n";

    if (y == 0) y = 0;
    cout << y << "\n";
    
    return 0;
}
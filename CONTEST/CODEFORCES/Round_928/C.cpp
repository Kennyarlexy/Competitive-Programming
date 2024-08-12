#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int f(int i) {
    int sum = 0;
    while (i > 0) {
        sum += (i % 10);
        i /= 10;
    }
    return sum;
}

int A[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int i = 1; i <= 200000; i++) {
        A[i] = A[i-1] + f(i);
    }
    
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        cout << A[n] << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[100005], B[1000005], C[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B[A[i]]++;
    }

    for (int i = 2; i <= 1000000; i++) {
        B[i] += B[i-1];
    }

    for (int i = 1; i <= n; i++) {
        C[B[A[i]]--] = A[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << C[i] << " \n"[i==n];
    }
    
    return 0;
}
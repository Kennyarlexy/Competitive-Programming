#include <bits/stdc++.h>
#define ll long long
#define se second 
#define fi first
using namespace std;

int A[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A+1, A+1+n);
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " \n"[i==n];
    }
    
    return 0;
}
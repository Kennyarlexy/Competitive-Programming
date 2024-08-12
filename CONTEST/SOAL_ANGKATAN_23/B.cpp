#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

string A[55];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    A[0] = A[N];

    cout << A[21 % N] << "\n";
    
    return 0;
}
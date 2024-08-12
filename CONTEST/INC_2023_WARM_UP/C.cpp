#include <bits/stdc++.h>
#define ll long long
using namespace std;

int D[100005];
int A[100005];

bool f(ll P, ll sum, ll k, ll X) {
    return P - sum*k >= X;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, P_0, X; cin >> N >> P_0 >> X;
    int sum = 0;
    A[0] = P_0;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        A[i+1] = A[i] + D[i];
        sum += D[i];
    }

    int ans = INT_MAX;
    bool OK = false;
    for (int i = 0; i < N; i++) {
        int k = 0;

        if (A[i] < X) continue;
    }
    
    return 0;
}
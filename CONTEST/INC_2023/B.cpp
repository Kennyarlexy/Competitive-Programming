#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int A[1005];

priority_queue<int> PQ;



int main() {
    fast_io();
    //use ll when possible!
    int N, M, K; cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    int i = 1;
    int sum = 0;
    while (i <= N) {
        sum += A[i];
        PQ.push(A[i]);
        ans++;
        if (sum > M) {
            if (K > 0) {
                K--;
                sum -= PQ.top(); PQ.pop();
            } else {
                ans--;
                break;
            }
        }
        i++;
    }
    cout << ans << "\n";

    return 0;
}
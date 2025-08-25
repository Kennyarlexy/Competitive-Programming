#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int i = 0;
    priority_queue<int> PQ;
    while (i < N) {
        i++;
        PQ.push(A[i]);
        M -= A[i];
        if (M < 0) {
            if (K > 0) {
                M += PQ.top(); PQ.pop();
                K--;
            } else {
                i--;
                break;
            }
        }
    }

    cout << i << "\n";
    
    return 0;
}
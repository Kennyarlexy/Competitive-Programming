#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

struct Custom {
    ll x, l, r;
};

Custom A[100005];
bool removed[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        A[i] = {x, i-1, i+1};
    }

    A[N].r = -1;
    priority_queue<pair<int, int>> PQ;
    for (int i = 1; i <= N-1; i++) {
        PQ.push({A[i].x & A[i+1].x, i});
    }

    ll X = 0;
    int k = 0;
    while (k < N-1) {
        auto [x_and, i] = PQ.top(); PQ.pop();
        if (removed[i]) continue;
        k++;
        X += x_and;
        removed[A[i].r] = true;
        A[i].r = A[A[i].r].r;
        PQ.push({A[i].x & A[A[i].r].x, i});
    }

    cout << X << "\n";
    
    return 0;
}
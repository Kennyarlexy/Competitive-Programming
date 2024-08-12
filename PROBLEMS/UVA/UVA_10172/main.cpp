#include <bits/stdc++.h>
#define ll long long
using namespace std;

queue<ll> A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll set; cin >> set;
    for (ll s = 1; s <= set; s++) {
        ll N, S, Q; cin >> N >> S >> Q;
        ll total = 0;
        for (ll i = 1; i <= N; i++) {
            ll Qi; cin >> Qi;
            total += Qi;
            A[i] = {};
            for (ll q = 1; q <= Qi; q++) {
                ll a; cin >> a;
                A[i].push(a);
            }
        }

        stack<ll> st;
        ll cnt = 0;
        ll i = 0;
        ll time = -2;
        while (cnt < total) {
            i++;
            if (i > N) i = 1;
            time += 2;
            while (!st.empty()) {
                if (st.top() == i) {
                    cnt++;
                } else if (A[i].size() < Q) {
                    A[i].push(st.top());
                } else {
                    break;
                }
                st.pop();
                time++;
            }

            while (!A[i].empty() && st.size() < S) {
                st.push(A[i].front());
                A[i].pop();
                time++;
            }
        }

        cout << time << "\n";
    }
    
    return 0;
}
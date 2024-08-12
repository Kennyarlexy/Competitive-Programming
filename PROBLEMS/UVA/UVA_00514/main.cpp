#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        while (true) {
            cin >> A[1];
            if (A[1] == 0) break;

            for (ll i = 2; i <= N; i++) {
                cin >> A[i];
            }

            stack<ll> st;
            ll i = 1;
            for (ll c = 1; c <= N; c++) {
                st.push(c);
                while (!st.empty() && st.top() == A[i]) {
                    st.pop();
                    i++;
                }
            }

            if (st.empty()) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }
    
    return 0;
}
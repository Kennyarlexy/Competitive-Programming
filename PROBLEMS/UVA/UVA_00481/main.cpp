#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<ll> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (cin >> n) {
        A.push_back(n);
    }

    ll LIS_len = 0, i_end = -1;
    // L[i] is currently the most optimal ending of the subsequence with length i
    vector<ll> L(A.size() + 5), L_id(A.size() + 5), p(A.size() + 5);

    for (ll i = 0; i < A.size(); i++) {
        // the longest subsequence which the ending can be replaced;
        ll len_to_replace = lower_bound(L.begin() + 1, L.begin() + LIS_len + 1, A[i]) - L.begin();
        L[len_to_replace] = A[i];
        L_id[len_to_replace] = i;

        p[i] = len_to_replace == 1 ? -1 : L_id[len_to_replace-1];

        if (len_to_replace > LIS_len) {
            LIS_len++;
            i_end = i;
        }
    }

    cout << LIS_len << "\n";
    
    return 0;
}
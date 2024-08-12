#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string A[200005];
string B[200005];


bool cmp1(string A, string B) {
    return A.length() > B.length();
}

bool cmp2(string A, string B) {
    string AB = A + B;
    string BA = B + A;
    return (AB > BA);
}

int main() {
    fast_io();
    //use ll when possible!
    ll N; cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll diff = 0;
    ll cnt = 0;
    sort(A, A + N, cmp1);
    for (ll i = 0; i < N; i++) {
        if (i > 0 && A[i].length() < B[i-1].length()) diff++;
        if (diff > 7) break;
        B[i] = A[i];
        cnt++;
    }

    sort(B, B + cnt, cmp2);
    for (ll i = 0; i < 7; i++) {
        cout << B[i];
    }
    cout << "\n";

    return 0;
}
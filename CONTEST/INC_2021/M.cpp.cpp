#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll K, S, N; cin >> K >> S >> N;

    if (N < K*S) { //N is less than minimum possible total points
        cout << "NO\n";
    } else if ((2*K-2)*S >= N) { //the sets are always finished with one of the team score exactly K, thus always possible
        cout << "YES\n";
    } else if (N % 2 == 0) { //if one or more of the set ends with both team scored more than K, always possible with even N
        cout << "YES\n";
    } else if (S > 1 && K > 2) { //but if N is odd, we can make one of the set scored with total of odd numbers
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
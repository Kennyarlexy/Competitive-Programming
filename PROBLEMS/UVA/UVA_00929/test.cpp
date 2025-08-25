#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(A, 127, sizeof(A));
    for (int i = 1; i <= 1000; i++) {
        cout << A[i] << " ";
    }

    cout << A[0] << " ";

    cout << LLONG_MAX << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[105];
ll pre[105];
ll tree[105];

ll sumq(ll R) {
    // returns sum from [1, R]
    ll sum = 0;
    while (R >= 1) {
        sum += tree[R];
        R -= (R & -R);
    }

    return sum;
}

void update(ll R, ll D) {
    //we only need the difference to update
    while (R <= 100) {
        tree[R] += D;
        R += (R & -R); //move to the next bigger range
    }    
}

int main() {
    fast_io();
    //input original array
    for (ll i = 1; i <= 100; i++) {
        A[i] = i*i;
    }

    //constructing pre-sum array to help building the tree, notice some difference since we stored original value in A, we can omit A in practice and direclty use pre to store input
    for (ll i = 1; i <= 100; i++) {
        pre[i] = pre[i-1] + A[i];
    }

    //build the tree with the help of pre
    for (ll i = 1; i <= 100; i++) {
        ll len = i & -i; //the length is a maximum power of 2 that divides i
        tree[i] = pre[i] - pre[i-len];
    }

    //querying the tree
    ll Q; cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        ll L, R; cin >> L >> R;
        ll sum1 = sumq(R) - sumq(L-1);
        ll sum2 = 0; //verify the result
        for (ll i = L; i <= R; i++) {
            sum2 += A[i];
        }
        cout << sum1 << " " << sum2 << "\n";
    }
    
    cout << "------------------------------------------------------------\n";
    update(1, 10); A[1] += 10;
    cin >> Q;
    for (ll q = 1; q <= Q; q++) {
        ll L, R; cin >> L >> R;
        ll sum1 = sumq(R) - sumq(L-1);
        ll sum2 = 0; //verify the result
        for (ll i = L; i <= R; i++) {
            sum2 += A[i];
        }
        cout << sum1 << " " << sum2 << "\n";
    }

    return 0;
}
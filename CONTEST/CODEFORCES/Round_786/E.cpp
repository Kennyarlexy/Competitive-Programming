#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int arr[200005];

int main() {
    fast_io();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int a = INT_MAX, b = INT_MAX;
    for (int i = 0; i < n; i++) {
        int shots = (arr[i] + 1) / 2;
        if (shots < b) {
            b = shots;
            if (b < a) swap(a, b);
        }
    }
    int res1 = a + b;

    int res2 = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        int center = fmax(arr[i], arr[i+1]);
        int adj = fmin(arr[i], arr[i+1]);
        int temp;
        if (adj*2 <= center) {
            temp = (center + 1) / 2;
        } else {
            temp = (center + adj + 2) / 3;
        }
        res2 = fmin(res2, temp);
    }

    int res3 = INT_MAX;
    for (int i = 0; i < n-2; i++) {
        int temp = (arr[i] + arr[i+2] + 1) / 2;
        res3 = fmin(res3, temp);
    }

    int arrsort[] = {res1, res2, res3};
    sort(arrsort, arrsort + 3);
    cout << arrsort[0] << "\n";

    return 0;
}
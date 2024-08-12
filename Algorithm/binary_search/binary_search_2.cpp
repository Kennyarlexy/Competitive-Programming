#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    int arr[] = {1, 3, 5, 7, 8, 10, 14, 15, 20, 40, 44, 53, 67, 73, 85, 98, 100};

    int i = 0;
    int target = 1;
    int len = sizeof(arr) / sizeof(int);
    for (int step = len/2; step >= 1; step/=2) {
        while (i+step < len && arr[i+step] <= target) {
            i += step;
        }
        if (arr[i] == target) break;
    }

    cout << "Found at index " << i << "\n";
    cout << arr[i] << "\n";

    int l = 0, r = len-1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (arr[m] < target) l = m+1;
        else if (arr[m] > target) r = m-1;
        else break;
    }

    cout << "Found at index " << m << "\n";
    cout << arr[m] << "\n";

    return 0;
}
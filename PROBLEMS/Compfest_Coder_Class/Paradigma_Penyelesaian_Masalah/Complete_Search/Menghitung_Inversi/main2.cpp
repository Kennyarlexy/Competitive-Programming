#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[100005];
int B[100005];

ll cnt = 0;

void merge_sort(int i, int j) {
    if (i == j) return;

    int m = (i+j) / 2;
    merge_sort(i, m);
    merge_sort(m+1, j);

    int l = i, r = m+1, x = i;
    while (l <= m && r <= j) {
        if (A[l] >= A[r]) {
            cnt += j-r+1;
            B[x++] = A[l++];
        } else B[x++] = A[r++];
    }

    while (l <= m) B[x++] = A[l++];
    while (r <= j) B[x++] = A[r++];

    for (x = i; x <= j; x++) A[x] = B[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    merge_sort(1, n);
    cout << cnt << "\n";
    
    return 0;
}

/*
15
3 5 3 7 8 7 65 4 4 5 7 7 5 4 4
*/
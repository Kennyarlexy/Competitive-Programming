#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[105][105];
string a, b;

int dpf(int i, int j, int n, int m) {
    if (i >= n && j >= m) return 0;
    if (i >= n) return m-j;
    if (j >= m) return n-i;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j]) return dp[i][j] = dpf(i+1, j+1, n, m);

    return dp[i][j] = min(dpf(i+1, j, n, m), min(dpf(i, j+1, n, m), dpf(i+1, j+1, n, m))) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int dist = dpf(0, 0, n, m);
    cout << dist << "\n";
    
    return 0;
}

/*
dvlskbjhslkerjgsofudhbpdvuobps9yfbr
dvdlbkjhdspbu9yaerp9gaqwr9upaeojfghsefg

asidhsdlkbjawirgsldfkjsdlkfjsdfbuorwpghafbjhzvxpoyawfpigewavsdfbdsglkjzdb
alskfjbhpizuvgbpaw9ugvaepijvbzdlkjbhzdpubohapoudfvhpozuchxdvbxovgbodysfbabfsrnwtjwyjwrn
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[105][105];
string a, b;

int dpf(int i, int j) {
    if (i < 0 && j < 0) return 0;
    if (i < 0) return j+1;
    if (j < 0) return i+1;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = min(dpf(i-1, j) + 1, min(dpf(i, j-1) + 1, dpf(i-1, j-1) + (a[i] != b[j])));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int dist = dpf(n-1, m-1);
    cout << dist << "\n";
    
    return 0;
}

/*
dvlskbjhslkerjgsofudhbpdvuobps9yfbr
dvdlbkjhdspbu9yaerp9gaqwr9upaeojfghsefg

asidhsdlkbjawirgsldfkjsdlkfjsdfbuorwpghafbjhzvxpoyawfpigewavsdfbdsglkjzdb
alskfjbhpizuvgbpaw9ugvaepijvbzdlkjbhzdpubohapoudfvhpozuchxdvbxovgbodysfbabfsrnwtjwyjwrn
*/
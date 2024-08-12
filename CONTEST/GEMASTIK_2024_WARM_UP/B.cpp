#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int conv(char a){
    int c = 0;
    c += a;
    c -= 65;
    return c;
}


int A[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 1000; i++) {
        A[i] = i;
        for (int j = 2; j <= 285000; j++) {
            A[j] += (A[j-1] + j*5) % 1000000007;
        }
    }
    
    vector<vector<string>> matA = {
        {"CB","AA","DD","DB"},
        {"CC","DC","CA","DA"},
        {"BA","AD","AC","BC"},
        {"BB","CD","AB","BD"}
    };
    vector<vector<string>> matB = {
        {"DA","DD","AC","BC"},
        {"DB","AB","CC","CD"},
        {"DC","BA","AD","AA"},
        {"CA","BB","CB","BD"}
    };
    string s;
    cin >> s;
    // cout << conv(s[0]);
    for(int i = 0; i < s.size(); i++){
        int baris, kolom;
        baris = conv(s[i]);
        kolom = conv(s[i+1]);
        string ans = matB[baris][kolom];
        // cout << ans;

        baris = conv(ans[0]);
        kolom = conv(ans[1]);
        ans = matA[baris][kolom];

        cout << ans;
        i++;
    }
    
    return 0;
}
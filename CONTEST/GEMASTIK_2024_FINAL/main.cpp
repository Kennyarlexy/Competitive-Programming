#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;

    map<char, queue<int>> MP;
    for (int i = 0; i < m; i++) {
        MP[s2[i]].push(i);
    }

    int x = 0, y = 0;
    string ans;
    for (int i = 0; i < n; i++) {
        if (!MP[s1[i]].empty()) {
// cout << "i = " << i << "\n";
            int j = MP[s1[i]].front(); MP[s1[i]].pop();
            while (x < i && y < j) {
                if (s1[x] < s2[y]) ans.push_back(s1[x++]);
                else ans.push_back(s2[y++]);
            }

            while (x < i) ans.push_back(s1[x++]);
            while (y < j) ans.push_back(s2[y++]);
            ans.push_back(s1[x]);
            x++;
            y++;
        }
    }

    while (x < n && y < m) {
        if (s1[x] < s2[y]) ans.push_back(s1[x++]);
        else ans.push_back(s2[y++]);
    }

    while (x < n) ans.push_back(s1[x++]);
    while (y < m) ans.push_back(s2[y++]);

    cout << ans << "\n";
    
    return 0;
}


/*
8 15
ZOPQRSTU
BCDEZFGHIJZKLMN

3 3
ABC
DBA

ADBAC

ABCDBA

3 3
DBA
ABC

DBAABC
*/
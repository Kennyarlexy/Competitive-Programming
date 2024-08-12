#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        char X; cin >> X;

        map<char, vector<string>> MP;
        for (int i = 1; i <= 2*n; i++) {
            string s; cin >> s;
            MP[s[1]].push_back(s);
        }

        ll x = 0, y = 0;
        for (auto &[key, val] : MP) {
            sort(val.begin(), val.end());
            if (key != X) x += (val.size() % 2);
            else y = val.size();
        }

        if (y >= x && (y-x) % 2 == 0) {
            int j = 0;
            for (auto &[key, val] : MP) {
                if (key == X) continue;

                int m = val.size();
                for (int i = 1; i < m; i+=2) {
                    cout << val[i-1] << " " << val[i] << "\n";
                }

                if (m % 2 == 1) {
                    cout << val[m-1] << " " << MP[X][j++] << "\n";
                }
            }

            auto& val = MP[X];
            int m = val.size();
            while (j+1 < m) {
                cout << val[j] << " " << val[j+1] << "\n";
                j += 2;
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    
    return 0;
}
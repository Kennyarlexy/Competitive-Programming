#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    map<string, int> M;
    int index = 1;
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            if (a == b) continue;
            string temp;
            temp += a;
            temp += b;
            M.insert(make_pair(temp, index));
            index++;
        }
    }
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        cout << M[s] << "\n";
    }

    return 0;
}
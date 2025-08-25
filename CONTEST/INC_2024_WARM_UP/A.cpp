#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    set<string> A;
    set<string> B;
    vector<string> C;
    for (int i = 1; i <= N; i++) {
        string s1, s2; cin >> s1 >> s2;
        if (i <= M) A.insert(s2);
        else {
            if (A.count(s2) == 0) {
                if (B.count(s2) == 0 && C.size() < K) {
                    B.insert(s2);
                    C.push_back(s1);
                }
            }
        }
    }

    cout << C.size() << "\n";
    for (auto &x : C) {
        cout << x << "\n";
    }
    
    
    return 0;
}
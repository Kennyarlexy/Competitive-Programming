#include <bits/stdc++.h>
using namespace std;

// #define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

unordered_set<string> TT, TT2;
vector<string> golden;

vector<string> all;

int main() {
    fast_io();
    //use ll when possible!
    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        string S, T; cin >> S >> T;
        if (i <= M) {
            TT.insert(T);
        } else {
            if (TT.count(T) == 0 && golden.size() < K) {
                golden.push_back(S);
                TT.insert(T);
            }
        }
    }

    cout << golden.size() << "\n";
    for (auto& team : golden) {
        cout << team << "\n";
    }

    return 0;
}
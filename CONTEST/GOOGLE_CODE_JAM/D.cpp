#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isTrigger[100001];
int fun[100001];
int adj[100001];
bool visited[100001];

ll traverse(int current, ll max = 0) {
    if (visited[current] || current == 0) return max;

    cout << "visiting node " << current << " with the fun of " << fun[current] << "\n";
    visited[current] = true;

    return traverse(adj[current], fmax(fun[current], max));
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        fill(isTrigger, isTrigger + 100001, true);
        fill(visited, visited + 100001, false);
        fill(adj, adj + 100001, 0);

        for (int i = 1; i <= N; i++) {
            cin >> fun[i];
        }

        for (int i = 1; i <= N; i++) {
            int P; cin >> P;
            isTrigger[P] = false;

            adj[i] = P;
        }

        vector<pair<int, int>> triggers;
        for (int i = 1; i <= N; i++) {
            if (isTrigger[i]) {
                triggers.push_back(make_pair(fun[i], i));
            }
        }
        sort(triggers.begin(), triggers.end());

        cout << "Trigger: ";
        for (auto& trigger : triggers) {
            cout << trigger.second << " ";
        }
        cout << "\n";

        ll sum = 0;
        for (auto& trigger : triggers) {
            sum += traverse(trigger.second);
        }

        cout << "Case #" << t << ": " << sum << "\n";
    }

    //100 + 90 + 90 + 100 + 100

    return 0;
}
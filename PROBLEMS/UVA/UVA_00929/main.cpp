#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int A[1005][1005];
vector<vector<int>> dist;

void djikstra(int N, int M) {
    priority_queue<tuple<int, int, int>> PQ;
    PQ.emplace(-A[1][1], 1, 1);
    dist[1][1] = A[1][1];
    while (!PQ.empty()) {
        auto [d, cr, cc] = PQ.top(); PQ.pop();
        d *= -1;
        if (cr == N && cc == M) break;
        if (dist[cr][cc] < d) continue;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 1 || nr > N) continue;
            if (nc < 1 || nc > M) continue;
            
            if (d + A[nr][nc] < dist[nr][nc]) {
                PQ.emplace(-1*(d + A[nr][nc]), nr, nc);
                dist[nr][nc] = d + A[nr][nc];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M; cin >> N >> M;

        dist = vector<vector<int>> (N+1, vector<int> (M+1, INF));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> A[i][j];
            }
        }

        djikstra(N, M);
        cout << dist[N][M] << "\n";
    }
    
    return 0;
}
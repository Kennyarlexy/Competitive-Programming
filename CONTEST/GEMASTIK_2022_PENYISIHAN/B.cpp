#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool vis[50005];
pair<ll, ll> dist[50005];
ll H[50005];

struct Edge {
    ll to;
    ll cost;
    Edge(ll _to, ll _cost) {
        to = _to;
        cost = _cost;
    }
};
vector<Edge> adjE[100005];

struct cmp {
    bool operator () (Edge a, Edge b) {
        return a.cost > b.cost;
    }
};

void dijkstra(ll start) {
    //create priority_queue in ascending order
    priority_queue<Edge, vector<Edge>, cmp> mypq;
    mypq.emplace(start, 0);
    dist[start].first = 0;
    
    while (!mypq.empty()) {
        //min is the minimum previously recorded distance for node current. note that there could be duplicate entries for the same node in priority_queue.
        ll current, prevMin;
        Edge temp = mypq.top();
        current = temp.to;
        prevMin = temp.cost;
        vis[current] = true;
        mypq.pop();
        if (dist[current].first < prevMin) continue; //is prevMin outdated?

        for (auto& edge : adjE[current]) {
            ll nextNode = edge.to, weight = edge.cost;
            if (vis[nextNode]) continue;

            ll newMin = min(dist[nextNode].first, prevMin + weight);
            dist[nextNode].first = newMin;
            dist[nextNode].second = max(weight, dist[nextNode].second);
            //store new minimum distance so that the next iteration will choose this entry in priority_queue as seen in line 32
            mypq.emplace(nextNode, newMin);
        }
    }
}

int main() {
    fast_io();
    //use ll when possible!
    ll N, M; cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        dist[i].first = LONG_LONG_MAX;
    }
    for (ll i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (ll i = 1; i <= M; i++) {
        ll u, v; cin >> u >> v;
        adjE[u].emplace_back(v, abs(H[u] - H[v]));
        adjE[v].emplace_back(u, abs(H[u] - H[v]));
    }

    dijkstra(1);

    for (ll i = 1; i <= N; i++) {
        cout << dist[i].first - dist[i].second << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll visited[100009];
ll p[100009];
vector<ll> adj[100009];
ll cnt = 0;
ll Min;

void dfs(ll k){
    if(visited[k]) return;
    visited[k] = true;
    Min = min(Min, p[k]);
    ++cnt;

    for(auto x: adj[k]){
        dfs(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n,k,B; cin >> n >> k >> B;

    for(ll i = 1; i <= n; i++){
        cin >> p[i];
    }

    for(ll i = 0; i < k; i++){
        ll a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<tuple<ll,ll,ll>> v;
    ll MinFinal = LLONG_MAX;
    ll sum = 0;
    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            cnt = 0;
            Min = LLONG_MAX;
            dfs(i);
            MinFinal = min(Min, MinFinal);
            v.emplace_back(cnt*Min, Min, cnt);
        }
    }

    sort(v.rbegin(), v.rend());

    for(auto &[w, Min, cnt]: v){
        if(Min==MinFinal){
            sum += w;
        }
        else if(B>0){
            --B;
            sum += MinFinal*cnt;
        }
        else{
            sum += w;
        }
    }

    cout << sum << "\n";

    return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long

int main() {
    cin.tie(NULL);
	ll t, w, v,e; cin >> t;
	string a,b;
	while(t--){
	    map<string, bool> ada; ll k = 0;
	    map<string, ll> nomer;
		cin >> v >> e; bool visited[v+5];
		ll dis[v+5]; bool isNeg = false;
		vector<pair<ll, ll>> n[v+5];
		fill(dis, dis + v +5, 5e7);
		memset(visited, false, sizeof(visited));
		dis[0] = 0;
		
		for(ll i = 0; i < e; i++){
			cin >> a >> b >> w;
			
			if(!ada[a]){
			    ada[a] = true;
			    nomer[a] = k;
			    k++;
			}
			
			if(!ada[b]){
			    ada[b] = true;
			    nomer[b] = k;
			    k++;
			}
		
			n[nomer[a]].pb(mp(nomer[b],0-w));
		}
		
		for(ll i = 1; i < v; i++){
			for(ll j = 0; j < v; j++){
				if(dis[j] != 5e7){
					for(auto x: n[j])
						dis[x.f] = min(dis[x.f], dis[j] + x.s);
				}
					// printf("dis[%d] = %d\n", x.f, dis[x.f]);
				}
		}
			
		for(ll i = 0; i < v; i++){
			for(auto x: n[i]){
				if(dis[x.f] > dis[i] + x.s && dis[i] != 5e7){
					isNeg = true;
					break;
				}
			}
		}
		
		if(isNeg) cout << "YA\n";
		else cout << "TIDAK\n";
		
		
	}
	return 0;
}
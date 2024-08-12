#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define ll long long
#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;

int ed[2600][2600];
int v,e,a,b, dis[5000];
bool visited[7000];

struct dat{
	int b,w;
};

vector<pair<int, int>> edge[4000];

int dj(int s){
	priority_queue<pair<int, int>> q;
	q.push(mp(s,0));
	while(!q.empty()){
		int we = 0 - q.top().s; int no = q.top().f;
		q.pop();
		if(!visited[no]){
			for(auto x: edge[no]){
				if(dis[x.f] > we + x.s){
					dis[x.f] = we + x.s;
					q.push(mp(x.f, 0 - dis[x.f]));
				}
			}
		}
		
	}
	return dis[b];
}
int main(){
	ios::sync_with_stdio(false);
	 cin >> v >> e >> a >> b;
	 memset(dis, 999999, sizeof(dis));
	for(int i = 0; i < e; i++){
		int aa, bb, w;
		cin >> aa >> bb >> w;
		edge[aa].pb(mp(bb, w));
		edge[bb].pb(mp(aa,w));
	}
	
	cout << dj(a) << endl;
	
}
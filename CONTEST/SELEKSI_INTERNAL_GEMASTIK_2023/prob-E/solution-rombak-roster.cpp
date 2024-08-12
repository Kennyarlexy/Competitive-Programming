#include <bits/stdc++.h>
using namespace std;

#define ll int

set<ll> role[30], dont[30];
vector<ll> roster; // bruteforce temp array
vector<vector<ll>> final; // Ans
vector<vector<string>> roster_lawan;
unordered_map<ll, string> ra; // int ==> player_name
map<string, ll> grade;

bool used[30]; // check player avaibility in bruteforce

ll nilai_player(string s){
	if(grade.find(s) != grade.end()) return grade[s];
	// cout << s << "\n";
	ll SUM = 0;
	for(ll i = 1; i < s.length(); i++){
		int A = (tolower(s[i-1]) - 'a'+1) - (tolower(s[i])- 'a'+1);
		int B = tolower(s[i-1]) + tolower(s[i]) - 2*'a' +2;
		// cout << "(" << A << "*" << B << ")" << " + ";
		SUM += A*B;
	}
	// cout << "\n";
	// cout << SUM << "\n";
	return grade[s] = SUM;
}
bool enemyExist(ll t){ // check enemy existence in roster[]
	for(auto y: dont[t]){
		if(used[y]) return true; // just check used[] h3h3
	}
	return false;
}

void brute(ll depth){
	if(depth == 6){ // print all
		for(int i = 1; i <= 5; i++){
			if(enemyExist(i)) return;
		}
		final.push_back(roster);
		return;
	}
	
	for(auto x: role[depth]){
		if(used[x]) continue; // if used before
		if(enemyExist(x)) continue; // if enemy exist
		
		// passed, usual recursive backtracking
		roster.push_back(x);
		used[x] = true;
		
		brute(depth+1);
		
		roster.pop_back();
		used[x] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll X; cin >> X;
	vector<string> best_roster;
	bool triggered = false;
	ll Max = INT_MIN;
	for(ll i = 1; i <= X; i++){
		string temp; cin >> temp;
		ra[i] = temp; // store player name
	}
	
	ll K; cin >> K;
	
	for(ll i = 0; i < K; i++){
		ll A, P; char Q;
		cin >> A >> P >> Q;
		if(Q=='*'){
			for(ll j = 1; j <= 5; j++){
				role[j].insert(A);
			}
		}
		else{
			ll q = Q - '0';
			if(P == 0) role[q].insert(A);
			else{
				dont[A].insert(q);

			}
		}
		
	}

	vector<string> temp;

	ll Y; cin >> Y;
	for(ll i = 0; i < Y; i++){
		string nama_tim; cin >> nama_tim;
		temp.clear();
		for(ll j = 0; j < 5; j++){
			string rosterI; cin >> rosterI;
			temp.push_back(rosterI);
		}
		roster_lawan.push_back(temp);
	}
	
	brute(1);

	if(final.size()==0){
		cout << -1 << "\n";
		return 0;
	}

	for(auto x: final){
		double sum_t = 0;
		for(auto y: roster_lawan){
			ll cnt = 5;
			auto Fi = x.begin();
			auto Li = y.begin();
			for(; Li != y.end(); Fi++, Li++){
				// cout << " = " << nilai_player(ra[*Fi]) << " - " << nilai_player(*Li) << " * " << cnt << "\n";
				double hasil = (double)(nilai_player(ra[*Fi])-nilai_player(*Li)) * cnt;
				sum_t += hasil;
				--cnt;
			}
		}
		if(sum_t > Max){
			triggered = true;
			temp.clear();
			for(auto el: x) temp.push_back(ra[el]);
			best_roster = temp;
            Max = sum_t;
		}
	}
	


	cout << Max << "\n";
	for(auto el: best_roster){
		cout << el << " ";
	} cout << "\n";

	
}

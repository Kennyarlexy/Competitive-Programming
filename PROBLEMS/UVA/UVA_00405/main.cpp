#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<string, vector<vector<string>>> MP;
map<string, bool> vis;

string f(vector<string> &msg) {
    for (auto& entry : MP[msg[0]]) {
        bool match = true;
        for (ll i = 1; i < 5; i++) {
            if (entry[i] != "*" && entry[i] != msg[i]) {
                match = false;
                break;
            }
        }
        if (match) return entry[0];
    }

    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    ll t = 0;
    while (cin >> N) { // N MTA
        MP = {};
        for (ll i = 1; i <= N; i++) {
            string MTA_name; ll M; // M entry
            cin >> MTA_name >> M;
            for (ll j = 1; j <= M; j++) {
                vector<string> entry(5);
                for (auto& data : entry) {
                    cin >> data;
                }
                MP[MTA_name].push_back(entry);
            }
        }
        ll K; cin >> K; //K msg
        cout << "Scenario # " << ++t << "\n";
        
        for (ll j = 1; j <= K; j++) {
            vis = {};
            vector<string> msg(5);
            for (auto& data : msg) {
                cin >> data;
            }
            
            cout << j;
            vis[msg[0]] = true;
            while (true) {
                string next_MTA = f(msg);
                if (next_MTA == "") {
                    cout << " -- unable to route at " << msg[0] << "\n";
                    break;
                } 
                else if (next_MTA == msg[0]) {
                    cout << " -- delivered to " << next_MTA << "\n";
                    break;
                } 
                else if (vis[next_MTA]) {
                    cout << " -- circular routing detected by " << next_MTA << "\n";
                    break;
                } 
                else {
                    vis[next_MTA] = true;
                    msg[0] = next_MTA;
                }
            }
        }
        cout << "\n";
    }
    
    return 0;
}

/*
5
NAULINS 3
HOUSTON US SHIP * UHDOWNTOWN
NAULINS US SHIP * UNO
DALLAS US AIR UT *
HOUSTON 4
HOUSTON US * UH UHDT
SANANTONIO US BUS UT UTSA
DALLAS US AIR UT *
NAULINS US SHIP * UNO
DALLAS 7
DALLAS US * UT UTD
DALLAS US * UT UTA
HOUSTON US * UH *
SANANTONIO US AIR UT UTSA
OKLAHOMA US BUS * OU
NAULINS US AIR * UNO
HOUSTON US SHIP * *
OKLAHOMA 3
OKLAHOMA US * * OU
DALLAS US AIR * *
SANANTONIO US BUS * *
SANANTONIO 5
HOUSTON * * * UNO
HOUSTON US BUS UH *
DALLAS US AIR * *
SANANTONIO US * UT UTSA
OKLAHOMA US BUS * *
5
SANANTONIO US AIR COLLEGE UNO
OKLAHOMA US BUS UH UHDT
DALLAS US SHIP COLLEGE UNO
NAULINS US AIR COLLEGE OU
HOUSTON US AIR UT UTSA
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool AC[105][15];
bool Participate[105];
ll Pen[105][15];

struct Entry {
    ll AC = 0, Pen = 0, team;
};

bool cmp(Entry A, Entry B) {
    if (A.AC == B.AC) {
        if (A.Pen == B.Pen) {
            return A.team < B.team;
        }
        return A.Pen < B.Pen;
    }
    return A.AC > B.AC;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    cin.ignore(1000, '\n');
    cin.ignore(1000, '\n');
    for (ll t = 1; t <= T; t++) {
        memset(AC, 0, sizeof(AC));
        memset(Pen, 0, sizeof(Pen));
        memset(Participate, 0, sizeof(Participate));
        string line;
        while (getline(cin, line)) {
            if (line.empty()) break;
            stringstream SS(line);
            ll team, prob, time; char L;
            SS >> team >> prob >> time >> L;

            Participate[team] = true;
            if (AC[team][prob]) continue;
            
            if (L == 'C') {
                AC[team][prob] = true;
                Pen[team][prob] += time;
            } else if (L == 'I') {
                Pen[team][prob] += 20;
            }
        }

        vector<Entry> A;

        for (ll team = 1; team <= 100; team++) {
            if (!Participate[team]) continue;
            Entry entry; entry.team = team;
            for (ll prob = 1; prob <= 9; prob++) {
                if (AC[team][prob]) {
                    entry.AC++;
                    entry.Pen += Pen[team][prob];
                }
            }
            A.push_back(entry);
        }
        
        sort(A.begin(), A.end(), cmp);
        for (ll i = 0; i < A.size(); i++) {
            cout << A[i].team << " " << A[i].AC << " " << A[i].Pen << "\n";
        }

        if (t < T) cout << "\n";
    }
    
    return 0;
}

/*
3

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C
*/
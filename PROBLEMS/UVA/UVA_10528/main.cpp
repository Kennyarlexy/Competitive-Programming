#include <bits/stdc++.h>
#define ll long long
using namespace std;

string notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

set<string> key[15];
ll step[] = {2, 2, 1, 2, 2, 2, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    for (ll base = 0; base < 12; base++) {
        ll i = base;
        for (ll j = 0; j < 7; j++) {
            key[base].insert(notes[i]);
            i = (i + step[j]) % 12;
        }
    }

    string line;
    while (getline(cin, line)) {
        if (line == "END") break;
        stringstream SS(line);
        set<string> song;
        string note;
        while (SS >> note) {
            song.insert(note);
        }

        vector<string> res;
        for (ll base = 0; base < 12; base++) {
            if (includes(key[base].begin(), key[base].end(), song.begin(), song.end())) {
                res.push_back(notes[base]);
            }
        }
        
        for (ll i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i < res.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll round;
    while (cin >> round) {
        if (round == -1) break;

        set<char> ans, guessed, correct;
        vector<char> seq;
        string a, b; cin >> a >> b;
        for (auto& ch : a) {
            ans.insert(ch);
        }

        for (auto& ch : b) {
            if (guessed.find(ch) == guessed.end()) {
                seq.push_back(ch);
                guessed.insert(ch);
            }
        }

        ll cnt = 0;
        bool OK = true;
        for (auto& ch : seq) {
            if (ans.find(ch) == ans.end()) cnt++;
            else correct.insert(ch);

            if (cnt == 7 && correct.size() != ans.size()) {
                OK = false;
                break;
            }
        }
        
        cout << "Round " << round << "\n";
        if (!OK) cout << "You lose.\n";
        else if (correct.size() != ans.size()) cout << "You chickened out.\n";
        else cout << "You win.\n";
    }
    
    return 0;
}
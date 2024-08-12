#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    set<string> res;
    while (getline(cin, line)) {
        string word;
        for (auto& ch : line) {
            ch = tolower(ch);
            if (!isalpha(ch) && !word.empty()) {
                res.insert(word);
                word = "";
            } else if (isalpha(ch)) {
                word.push_back(ch);
            }
        }
        if (!word.empty()) res.insert(word);
    }

    for (auto& d : res) {
        cout << d << "\n";
    }
    
    return 0;
}

/*
Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the

road. The sign read: "Disneyland Left."
So they went home.
*/
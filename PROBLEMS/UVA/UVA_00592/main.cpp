#include <bits/stdc++.h>
#define ll long long
using namespace std;


/*
    scenarios:
    {from, time}
    {from, to, type}
    {from, to, not, type}
*/

/*
    
*/

unordered_map<string, int> dict = {
    {"divine", 0},
    {"evil", 1},
    {"human", 2},
    {"not", 3},
    {"lying", 4},
    {"day", 5},
    {"night", 6},
};

void parse(string &s, vector<int> &res) {
    string substr;
    for (auto ch : s) {
        if (ch == ':') continue;

        if (ch == ' ' || ch == '.') {
            if (substr == "am" || substr == "is") {
                substr = "";
                continue;
            }

            if (substr.size() == 1) res.push_back(substr[0] - 'A');
            else res.push_back(dict[substr]);

            substr = "";
        } else substr.push_back(ch);
    }

    assert(substr.empty());
}

pair<int, int> type[][3] = {
    {
        {0, 0},
        {1, 1},
        {2, 0}
    },
    {
        {0, 0},
        {1, 1},
        {2, 1}
    }
};

pair<int, int> assume[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        cin.ignore(10, '\n');

        vector<vector<int>> all; all.reserve(n);
        for (int i = 1; i <= n; i++) {
            string s; getline(cin, s);
            vector<int> res; parse(s, res);
            all.push_back(res);
        }

        for (int i = 0; i < 2; i++)
        for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
        for (int c = 0; c < 3; c++)
        for (int d = 0; d < 3; d++)
        for (int e = 0; e < 3; e++) {
            assume[0] = type[a][i];
            assume[1] = type[b][i];
            assume[2] = type[c][i];
            assume[3] = type[d][i];
            assume[4] = type[e][i];
        }
    }
    
    return 0;
}
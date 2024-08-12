#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

string qwerty1[4][14] = {
    {"`~", "1!", "2@", "3#", "4$", "5%", "6^", "7&", "8*", "9(", "0)", "-_", "=+", ""},
    {"", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[{", "]}", "\\|"},
    {"", "", "", "", "", "g", "h", "", "", "", "", "'\"", "", ""},
    {"", "z", "x", "c", "v", "b", "n", "m", ",<", ".>", "/?", "", "", ""}
};

string qwerty2[4][14] = {
    {"`~", "1!", "2@", "3#", "4$", "5%", "6^", "7&", "8*", "9(", "0)", "-_", "=+", ""},
    {"", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[{", "]}", "\\|"},
    {"", "a", "s", "d", "", "", "", "", "k", "l", ";:", "'\"", "", ""},
    {"", "z", "x", "c", "v", "b", "n", "m", ",<", ".>", "/?", "", "", ""}
};

string dvorak[4][14] = {
    {"`~", "1!", "2@", "3#", "q", "j", "l", "m", "f", "p", "/?", "[{", "]}", ""},
    {"", "4$", "5%", "6^", ".>", "o", "r", "s", "u", "y", "b", ";:", "=+", "\\|"},
    {"", "7&", "8*", "9(", "a", "", "", "", "", "c", "k", "-_", "", ""},
    {"", "0)", "z", "x", ",<", "i", "n", "w", "v", "g", "'\"", "", "", ""}
};

string homeQwerty1 = "asdfjkl;";
string homeQwerty2 = "fghj";
string homeDvorak = "ehtd";

ll colQwerty1[300];
ll colQwerty2[300];
ll colDvorak[300];

double distQwerty1[300];
double distQwerty2[300];
double distDvorak[300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    colQwerty1['a'] = 1;
    colQwerty1['s'] = 2;
    colQwerty1['d'] = 3;
    colQwerty1['f'] = 4;
    colQwerty1['j'] = 7;
    colQwerty1['k'] = 8;
    colQwerty1['l'] = 9;
    colQwerty1[';'] = 10;

    colQwerty2['f'] = 4;
    colQwerty2['g'] = 5;
    colQwerty2['h'] = 6;
    colQwerty2['j'] = 7;
    
    colDvorak['e'] = 5;
    colDvorak['h'] = 6;
    colDvorak['t'] = 7;
    colDvorak['d'] = 8;

    for (ll r = 0; r < 4; r++)
    for (ll c = 0; c < 14; c++)
    for (auto& ch : qwerty1[r][c]) {
        distQwerty1[ch] = 1e9;
        for (auto& h : homeQwerty1) {
            ll dr = abs(r-2);
            ll dc = abs(c-colQwerty1[h]);
            double dist = sqrt(dr*dr + dc*dc);
            distQwerty1[ch] = min(distQwerty1[ch], 2*dist);
        }
    }

    for (ll r = 0; r < 4; r++)
    for (ll c = 0; c < 14; c++)
    for (auto& ch : qwerty2[r][c]) {
        distQwerty2[ch] = 1e9;
        for (auto& h : homeQwerty2) {
            ll dr = abs(r-2);
            ll dc = abs(c-colQwerty2[h]);
            double dist = sqrt(dr*dr + dc*dc);
            distQwerty2[ch] = min(distQwerty2[ch], 2*dist);
        }
    }

    for (ll r = 0; r < 4; r++)
    for (ll c = 0; c < 14; c++)
    for (auto& ch : dvorak[r][c]) {
        distDvorak[ch] = 1e9;
        for (auto& h : homeDvorak) {
            ll dr = abs(r-2);
            ll dc = abs(c-colDvorak[h]);
            double dist = sqrt(dr*dr + dc*dc);
            distDvorak[ch] = min(distDvorak[ch], 2*dist);
        }
    }

    string line;
    while (getline(cin, line)) {
        double sumQ1 = 0, sumQ2 = 0, sumD = 0;
        for (auto& ch : line) {
            if (ch == ' ') continue;
            sumQ1 += distQwerty1[tolower(ch)];
            sumQ2 += distQwerty2[tolower(ch)];
            sumD += distDvorak[tolower(ch)];
        }
        cout << fixed << setprecision(2) << sumQ1 << " " << sumQ2 << " " << sumD << "\n";
    }
    
    return 0;
}
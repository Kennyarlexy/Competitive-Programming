#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isvowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o';
}

string f(string& s) {
    string a, b, c = "ay";
    if (!isvowel(s[0])) {
        a = s.substr(1);
        b = s[0];
    } else {
        a = s;
    }
    return a + b + c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        string word;
        for (auto& ch : line) {
            if (isalpha(ch)) word.push_back(ch);
            else {
                if (word != "") cout << f(word);
                word = "";
                cout << ch;
            }
        }
        if (word != "") cout << f(word);
        cout << "\n";
    }
    
    return 0;
}
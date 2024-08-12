#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    deque<string> A;
    set<string> exist;
    while (true) {
        getline(cin, line);
        if (line == "0") break;

        string word;
        ll j = 0;
        for (ll i = 0; i < line.length(); i++) {
            char ch = line[i];
            if (isdigit(ch)) {
                j = 10*j + ch - '0';
                if (i == line.length()-1 || !isdigit(line[i+1])) {
                    string t = A[j-1];
                    cout << A[j-1];
                    A.erase(A.begin()+j-1);
                    A.push_front(t);
                }
            } else {
                j = 0;
                if (isalpha(ch)) {
                    word.push_back(ch);
                } else if (word != "") {
                    if (exist.find(word) == exist.end()) {
                        exist.insert(word);
                        A.push_front(word);
                    }
                    word = "";
                }
                cout << ch;
            }

        }
        if (word != "" && exist.find(word) == exist.end()) {
            exist.insert(word);
            A.push_front(word);
        }
        
        cout << "\n";
    }
    
    return 0;
}

/*
Dear Sally,

   Please, please do it--1 would 4
Mary very, 1 much. And 4 6
8 everything in 5's power to make
14 pay off for you.

   -- Thank 2 18 18--
0
*/
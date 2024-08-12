#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s)) {
        ll pos = 2; //2 means right, 1 means left, cursor position
        deque<char> front;
        deque<char> end;
        for (auto& ch : s) {
            if (ch == '[') {
                for (auto& d : front) {
                    end.push_front(d);
                }
                pos = 1;
                front = {};
                continue;
            }
            else if (ch == ']') {
                for (auto& d : front) {
                    end.push_front(d);
                }
                pos = 2;
                front = {};
                continue;
            }

            if (pos == 1) {
                front.push_front(ch);
            } else {
                end.push_back(ch);
            }
        }

        for (auto& d : front) {
            end.push_front(d);
        }

        for (auto& ch : end) {
            cout << ch;
        }
        cout << "\n";
    }
    
    return 0;
}
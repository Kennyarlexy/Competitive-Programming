#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string input; cin >> input;
        unordered_set<char> used;
        cout << "Case #" << t << ": ";
        for (auto& ch : input) {
            used.insert(ch);
        }

        if (used.size() == 1) {
            cout << input;
        } else {
            string temp;
            for (int i = 0; i < input.length() - 1; i++) {
                temp += input[i];
                if (input[i] == input[i+1] && i < input.length() - 2) continue;

                if (input[i] < input[i+1]) {
                    cout << temp;
                }
                cout << temp;
                temp = "";
            }
            cout << input.back();
        }
        cout << "\n";
    }

    return 0;
}
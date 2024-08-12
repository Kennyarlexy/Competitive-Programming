#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    A.reserve(100005);
    for (ll t = 1; t <= T; t++) {
        string line;
        A.resize(1);
        unordered_map<string, ll> cnt;
        while (true) {
            getline(cin, line);
            if (line == "END") break;
            string word;
            for (auto& ch : line) {
                if (!isalpha(ch) && !word.empty()) {
                    A.push_back(word);
                    cnt[word] = 0;
                    word = "";
                } else if (isalpha(ch)) {
                    word.push_back(ch);
                }
            }

            if (!word.empty()) {
                A.push_back(word);
                cnt[word] = 0;
            }
        }

        ll l = 1, r = 1, p = 1, q = 1e9;
        unordered_set<string> unique; unique.reserve(cnt.size());
        while (r <= A.size()) {
            cnt[A[r]]++;
            unique.insert(A[r]);
            while (unique.size() == cnt.size() && cnt[A[l]] > 1) {
                cnt[A[l]]--;
                l++;
            }

            if (unique.size() == cnt.size() && r-l < q-p) {
                p = l, q = r;
            }
            r++;
        }
        cout << "Document " << t << ": " << p << " " << q << "\n";
    }
    
    return 0;
}
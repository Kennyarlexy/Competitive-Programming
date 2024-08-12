#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool used[300];
string s;
vector<string> A;
void f(ll i) {
    if (i > 5) return;
    for (char ch = (s.empty()?'a':s.back()+1); ch <= 'z'; ch++) {
        if (used[ch]) continue;
        s.push_back(ch); used[ch] = true;
        A.push_back(s); f(i+1);
        s.pop_back(); used[ch] = false;
    }
}

bool cmp(string A, string B) {
    if (A.length() == B.length()) {
        return A < B;
    }
    return A.length() < B.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    A.reserve(85000);
    
    f(1);
    sort(A.begin(), A.end(), cmp);
    unordered_map<string, ll> MP; MP.reserve(85000);
    for (ll i = 0; i < A.size(); i++) {
        MP[A[i]] = i+1;
    }
    string s;
    while (cin >> s) cout << MP[s] << "\n";
    
    return 0;
}
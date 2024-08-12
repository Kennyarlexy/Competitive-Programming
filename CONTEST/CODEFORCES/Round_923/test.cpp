#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    s.reserve(100005);
    char ch = 'a';
    auto __time_1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100000; i++) {
        s.push_back(ch);
    }
    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    cout << exe_time_ms.count() << "ms\n";
    cout << s.size() << "\n";
    
    return 0;
}
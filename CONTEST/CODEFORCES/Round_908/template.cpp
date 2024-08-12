#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < 1000000; ++i) {
        A[i] = rand() % 100000 + 1;
    }
    unordered_set<int> S;

    auto __time_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        S.insert(A[i]);
    }

    // sort(A, A + 1000000);
    // int unique = 1;
    // for (int i = 1; i < 1000000; i++) {
    //     if (A[i] != A[i-1]) unique++;
    //     // cout << A[i] << " ";
    // }
    auto __time_2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> exe_time_ms = __time_2 - __time_1;
    cout << exe_time_ms.count() << "ms\n";

    cout << S.size() << "\n";
    // cout << unique << "\n";


    
    return 0;
}
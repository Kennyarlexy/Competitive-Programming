#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    string A = "01:00";
    string B = "01:01";
    if (B >= A) {
        cout << "works\n";
    }

    return 0;
}
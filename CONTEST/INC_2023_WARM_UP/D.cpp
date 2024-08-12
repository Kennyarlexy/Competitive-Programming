#include <bits/stdc++.h>
using namespace std;

int bit[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Q; cin >> Q;

    int on = 0;
    for (int q = 1; q <= Q; q++) {
        char ch; int pos;
        cin >> ch >> pos;
        if (ch == '+') {
            bit[pos]++;
            on++;

            if (bit[pos] == 0) on--;
            while (bit[pos] == 2) {
                bit[pos+1]++; bit[pos];
                pos++;
            }
        }
        else bit[pos]++;


    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int count_0[200005];
int count_1[200005];

int main() {
    fast_io();
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        memset(count_0, 0, sizeof(count_0));
        memset(count_1, 0, sizeof(count_1));
        string s; cin >> s;

        int total_0 = 0;
        int total_1 = 0;

        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                total_0++;
            } else {
                total_1++;
            }
            count_0[i] = total_0;
            count_1[i] = total_1;
        }

        
        int diff_left = -1;
        int left = -1;
        for (int i = 0; i < len; i++) {
            int temp = count_0[i] - count_1[i];
            if (temp > diff_left) {
                diff_left = temp;
                left = i;
            }
        }

        int removed_0 = count_0[left];
        int removed_1 = count_1[left];

        int diff_right = -1;
        int right = len;
        for (int i = left+1; i < len; i++) {
            int temp = (total_0 - count_0[i-1]) - (total_1 - count_1[i-1]);
            if (temp > diff_right) {
                diff_right = temp;
                right = i;
            }
        }
        cout << left << "\n";
        cout << right << "\n";

        removed_0 += total_0 - count_0[right-1];
        removed_1 += total_1 - count_1[right-1];
        cout << removed_0 << " " << removed_1 << "\n";

        int zeroLeft = total_0 - removed_0;
        int result = max(removed_1, zeroLeft);
        cout << result << "\n";
    }

    return 0;
}
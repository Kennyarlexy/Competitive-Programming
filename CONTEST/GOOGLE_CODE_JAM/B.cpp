#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int target = 1000000;
        int result[4];
        int ink[3][4];
        for (int printer = 0; printer < 3; printer++) {
            for (int color = 0; color < 4; color++) {
                cin >> ink[printer][color];
            }
        }

        for (int color = 0; color < 4; color++) {
            if (target <= 0) {
                result[color] = 0;
            } else {
                int compare[] = {ink[0][color], ink[1][color], ink[2][color]};
                sort(compare, compare + 3);

                int min = compare[0];
                if (min > target) {
                    min = target;
                }
                target -= min;
                result[color] = min;
            }
        }

        cout << "Case #" << t << ": ";
        if (target <= 0) {
            for (int i = 0; i < 4; i++) {
                cout << result[i];
                if (i < 3) cout << " ";
            }
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }

    return 0;
}
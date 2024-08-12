#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int ADD = 40000;

int dp[45][80010];
int T[45];
int N, F;
vector<char> sign;

bool dpf(int i, int x) {
    if (i > N) return x == F;

    if (dp[i][x+ADD] != -1) return dp[i][x+ADD];

    bool plus = dpf(i+1, x+T[i]);
    bool minus = dpf(i+1, x-T[i]);
    
    if (plus && minus) {
        sign[i] = '?';
        return dp[i][x+ADD] = 1;
    } else if (plus) {
        sign[i] = (sign[i] == '-' || sign[i] == '?') ? '?' : '+';
        return dp[i][x+ADD] = 1;
    } else if (minus) {
        sign[i] = (sign[i] == '+' || sign[i] == '?') ? '?' : '-';
        return dp[i][x+ADD] = 1;
    }

    return dp[i][x+ADD] = 0;
}

void reset(int i, int x) {
    if (i > N) return;
    if (dp[i][x+ADD] == -1) return;

    dp[i][x+ADD] = -1;
    reset(i+1, x+T[i]);
    reset(i+1, x-T[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    while (cin >> N >> F && (N || F)) {
        sign = vector<char> (N+1, '*');
        for (int i = 1; i <= N; i++) {
            cin >> T[i];
        }

        bool possible = dpf(1, 0);
        if (possible) {
            // assert(sign[1] != '*');
            for (int i = 1; i <= N; i++) {
                cout << sign[i];
            }
            cout << "\n";
        } else {
            cout << "*\n";
        }

        reset(1, 0);
    }
    
    return 0;
}

/*
5 7
1
2
3
4
5
4 15
3
5
7
11
5 12
6
7
7
1
7
0 0

5 12
6
7
7
1
7
0 0

40 12345
123
536
534
342
298
15
234
1
5
22
6
5
67
56
78
87
4
3
6
344
25
25
2
5
2
325
5
6
67
7
7
25
2
5
2
325
5
6
67
7
0 0

40 16000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
0 0
*/
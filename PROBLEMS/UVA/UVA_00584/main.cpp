#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll A[105];
ll B[105]; //bonus
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (getline(cin, line)) {
        if (line == "Game Over") break;
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        stringstream SS(line);
        char roll;
        ll i = 0, F = 0;
        while (SS >> roll) {
            i++; F++;
            if (roll == 'X') {
                A[i] = 10;
                B[i] = 2;
            } else {
                A[i] = (roll - '0');
                if (SS >> roll) {
                    i++;
                    if (roll == '/') {
                        A[i] = 10 - A[i-1];
                        B[i] = 1;
                    } else {
                        A[i] = (roll - '0');
                    }
                }
            }
        }

        ll total = 0;
        for (ll j = 1; j <= i; j++) {
            total += A[j];
            if (B[j] == 2) {
                total += A[j+1] + A[j+2];
                if (j == i-2 && F > 10) break;
            } else if (B[j] == 1) {
                total += A[j+1];
                if (j == i-1 && F > 10) break;
            }
        }

        cout << total << "\n";
    }
    
    return 0;
}

/*
1 0 1 / 2 2 X 3 3 X 1 / 3 / X 1 2
Game Over
*/

/*
X X X X X X X X 6 / X X X
Game Over
*/

/*
1 0 1 / 2 2 X 3 3 X 1 / 3 / 1 / X 8 0
Game Over
*/

/*
1 0 1 / 2 2 X 3 3 X 1 / 3 / 1 / 8 / 9
Game Over
*/

/*
X 7 0 3 2 0 0 3 2 1 6 X 5 / X 3 2
Game Over
*/
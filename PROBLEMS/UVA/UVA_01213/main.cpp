#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int n = 1120;
const int k = 14;
vector<int> primes;
vector<bool> sieve(n+5);
void f() {
    sieve[0] = sieve[1] = true;
    for (int i = 2; i*i <= n; i++) {
        if (sieve[i]) continue;
        for (int j = i*i; j <= n; j += i) {
            sieve[j] = true;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) primes.push_back(i);
    }
}

ll dp[2][n+5][k+5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f();

    int m = primes.size();

// for (int i = 0; i < m; i++) cout << primes[i] << " \n"[i==m-1]; return 0;
    
    int now = 0, past = 1;
    dp[now][0][0] = 1;

    for (int i = 0; i < m; i++) {
        swap(now, past);
        for (int j = 0; j <= n; j++) {
            for (int x = 0; x <= k; x++) {
                dp[now][j][x] = dp[past][j][x];
                if (j - primes[i] >= 0) dp[now][j][x] += dp[past][j - primes[i]][x-1];
            }

        }
    }

    int a, b;
    while (cin >> a >> b && a && b) {
        cout << dp[now][a][b] << "\n";
    }
    
    return 0;
}
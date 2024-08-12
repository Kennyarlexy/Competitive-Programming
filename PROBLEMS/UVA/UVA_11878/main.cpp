#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll a, b, c;
    char s;
    ll score = 0;
    while (true) {
        ll n = scanf("%lld%c%lld%*c%lld", &a, &s, &b, &c);
        if (n == 3) scanf("%*s");
        else if (n == EOF) break;

        if (n == 4) {
            if (s == '+' && a + b == c) score++;
            else if (s == '-' && a - b == c) score++;
        }
    }
    printf("%lld\n", score);
    
    return 0;
}
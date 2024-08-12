#include <bits/stdc++.h>
#define ll long long
using namespace std;

char type[100];
char team[100];
ll score;

ll A[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll f(ll x) {
    string s = to_string(x);
    ll sum = 0;
    for (auto& ch : s) {
        sum += A[ch - '0'];
    }
    return sum;
}

int main() {
    ll h, m, s;
    ll t = 0;
    while (scanf("%*s %lld:%lld:%lld", &h, &m, &s) != EOF) {
        ll home = 0, guest = 0;
        ll prev = h*3600 + m*60 + s; //time converted to seconds
        ll res = 0;
        while (true) {
            scanf("%s %lld:%lld:%lld", &type, &h, &m, &s);
            ll cur = h*3600 + m*60 + s;
            res += (f(home) + f(guest)) * (cur - prev);
            
            if (strcmp(type, "END") == 0) break;

            scanf("%s %lld", &team, &score);
            if (strcmp(team, "home") == 0)
                home += score;
            else
                guest += score;
            
            prev = cur;
        }

        printf("Case %lld: %lld\n", ++t, res);
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll, ll> Begin[] = {
    {1, 21},
    {2, 20},
    {3, 21},
    {4, 21},
    {5, 22},
    {6, 22},
    {7, 23},
    {8, 22},
    {9, 24},
    {10, 24},
    {11, 23},
    {12, 23}
};

pair<ll, ll> End[] = {
    {2, 19},
    {3, 20},
    {4, 20},
    {5, 21},
    {6, 21},
    {7, 22},
    {8, 21},
    {9, 23},
    {10, 23},
    {11, 22},
    {12, 22},
    {1, 20}
};

char Sign[12][20] = {
    "aquarius",
    "pisces",
    "aries",
    "taurus",
    "gemini",
    "cancer",
    "leo",
    "virgo",
    "libra",
    "scorpio",
    "sagittarius",
    "capricorn"
};

ll dim[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ll T;;
    scanf("%lld", &T);
    for (ll t = 1; t <= T; t++) {
        ll MM, DD, YYYY;
        scanf("%2lld%2lld%4lld", &MM, &DD, &YYYY);
        ll k = 40*7;

        while (k > 0) {
            dim[2] = ((YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400 == 0 ? 29 : 28);

            DD += min(k, dim[MM]);
            k -= min(k, dim[MM]);
            if (DD > dim[MM]) {
                DD -= dim[MM];
                MM++;
            }
            if (MM == 13) {
                MM = 1; 
                YYYY++;
            }
        }

        bool capricorn = true;
        pair<ll, ll> cur = {MM, DD};
        printf("%lld ", t);
        if (MM < 10) printf("0");
        printf("%lld/", MM);
        if (DD < 10) printf("0");
        printf("%lld/", DD);
        ll z = 1;
        while (z++ < 4 - YYYY/10) printf("0");
        printf("%lld ", YYYY);

        for (ll i = 0; i < 11; i++) {
            if (cur >= Begin[i] && cur <= End[i]) {
                printf("%s\n", Sign[i]);
                capricorn = false;
                break;
            }
        }

        if (capricorn)
            printf("capricorn\n");
    } 
    
    return 0;
}
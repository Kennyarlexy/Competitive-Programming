#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[4], B[4];

int main() {
    ll T;
    scanf("%lld", &T);

    for (ll t = 1; t <= T; t++) {
        scanf("%lld:%lld %lld:%lld", &A[0], &A[1], &A[2], &A[3]);
        scanf("%lld:%lld %lld:%lld", &B[0], &B[1], &B[2], &B[3]);

        ll tw = (A[2]*60 + A[3]) - (A[0]*60 + A[1]);
        ll tm = (B[2]*60 + B[3]) - (B[0]*60 + B[1]);
        ll start = LONG_LONG_MAX, end = LONG_LONG_MIN;
        for (ll i = 0; i < 4; i+=2) {
            start = min(start, A[i]*60 + A[i+1]);
            start = min(start, B[i]*60 + B[i+1]);
            end = max(end, A[i]*60 + A[i+1]);
            end = max(end, B[i]*60 + B[i+1]);
        }

        if (end - start > tw + tm)
            printf("Case %lld: Hits Meeting\n", t);
        else
            printf("Case %lld: Mrs Meeting\n", t);
    }
    
    return 0;
}
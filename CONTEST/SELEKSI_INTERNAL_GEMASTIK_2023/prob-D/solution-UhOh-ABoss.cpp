#include <bits/stdc++.h>
#define ll long long
using namespace std;

int P[10];
int S[10];

ll f(ll time) { // return the number of total dmg
    ll dmg = 0;
    for (int i = 1; i <= 4; i++) {
        dmg += time/S[i] * P[i];
    }
    return dmg;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> P[1] >> P[2] >> P[3] >> P[4];
    cin >> S[1] >> S[2] >> S[3] >> S[4];
    ll HP; cin >> HP;

    ll time = 1e14;
    for (ll step = time/2; step >= 1; step/=2) {
        while (time-step > 0 && f(time-step) >= HP) time -= step;
    }
    cout << time << "\n";

    return 0;
}


/*
p1 p2 p3 p4 [1..1000]
s1 s2 s3 s4 [1..100]
HP [1.1e12]


1 2 3 4
2 3 3 2
15

1 1 1 1
1 2 3 4
20

7 4 5 8
10 10 10 2
22

5 6 7 8
3 5 10 3
435387559654645

5 6 7 8
3 5 10 3
435387559

1 1 1 1
100 100 100 100
1000000000000

123 53 723 145
10 54 25 75
34525233
*/
#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define dy first
#define dx second
#define Point pair<ll, ll>
#define Gradient pair<ll, ll>

using namespace std;

Point P[4005];
ll Positive[205][205], Negative[205][205];

// map<ll, map<ll, ll>> Positive, Negative;

Gradient get_gradient(Point A, Point B) {
    ll dx = B.x - A.x;
    ll dy = B.y - A.y;
    return {dy, dx};
}

// called when not a vertical or horizontal line
Gradient normalize(Gradient g) {
    auto [dy, dx] = g;
    ll gcd = __gcd(dy, dx);
    dy /= gcd;
    dx /= gcd;
    if (dx < 0) {
        dx = -dx;
        dy = -dy;
    }

    return {dy, dx};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        cin >> P[i].x >> P[i].y;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ll Horizontal = 0, Vertical = 0;
        // Positive = {}, Negative = {};
        memset(Positive, 0, sizeof(Positive));
        memset(Negative, 0, sizeof(Negative));
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            auto g = get_gradient(P[i], P[j]);
            if (g.dx == 0) {
                ans += Horizontal;
                Vertical++;
            } else if (g.dy == 0) {
                ans += Vertical;
                Horizontal++;
            } else {
                auto [dy, dx] = normalize(g);
                if (dy < 0) {
                    ans += Positive[dx][-dy];
                    Negative[-dy][dx]++;
                } else {
                    ans += Negative[dx][dy];
                    Positive[dy][dx]++;
                }
            }
        }
    }
    cout << ans << "\n";

    
    return 0;
}

/*
5
1 -4
-1 -1
3 -1
1 -2
0 3
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

//MST, CHECK CONSTRAINTS, CHECK CONSTRAINTS, CHECK CONSTRAINTS, -------------------------------------------------------------
ll N, M;

struct Edge {
    ll from;
    ll to;
    ll cost;
    Edge(ll f, ll t, ll c) {
        from = f;
        to = t;
        cost = c;
    }
};

struct cmp {
    bool operator () (Edge A, Edge B) {
        return B.cost < A.cost;
    }
};

priority_queue<Edge, vector<Edge>, cmp> PQ;
vector<pair<ll, ll>> adj[100005];
bool vis[100005];

void addE(ll u) {
    for (auto& v : adj[u]) {
        if (vis[v.first]) continue;
        PQ.emplace(u, v.first, v.second);
    }
}

ll mst(ll u) {
    vis[u] = true;
    addE(u);
    ll E = 0;
    ll EM = M-1;
    ll total = 0;
    while (!PQ.empty() && E < EM) {
        Edge e = PQ.top(); PQ.pop();
        if (vis[e.to]) continue;

        E++;
        vis[e.to] = true;
        total += e.cost;
        addE(e.to);
    }

    return total;
}

//Combinatorics--------------------------------------------------------------------------
//combination implementation
//be careful because some combinations are impossible, like C(1, 2); C(1, 5); C(99, 100); etc
ll C(ll n, ll r) {
    if (n < r) return 0;

    ll res = 1;
    ll k = n - r;
    ll d = 2;
    if (k < r) swap(k, r);
    for (ll x = n; x > k; x--) {
        res *= x;
        while (d <= r && res % d == 0) {
            res /= d;
            d++;
        }
    }

    return res;
}

//permutation implementation
ll P(ll n, ll r) {
    if (n < r) return 0;

    ll res = 1;
    ll k = n - r;
    for (ll x = n; x > k; x--) {
        res *= x;
    }

    return res;
}


//factorial implementation
ll F(ll x) {
    if (x == 0) return 1;
    ll res = 1;
    for (ll k = x; k >= 2; k--) {
        res *= k;
    }
    
    return res;
}

//modular exponentiation implementation
ll modexp(ll X, ll exp, ll mod = 1000000007) {
    if (exp == 0) return 1;
    
    ll temp = modexp(X, exp/2, mod);
    ll res = (temp * temp) % mod;
    if (exp % 2 == 1) res = (res * X) % mod;

    return res;
}


//Sequence And Series
ll Un(ll n, ll a, ll b) {
    ll res = a + (n - 1)*b;
    return res;
}

ll Sn(ll n, ll a, ll b) {
    ll res = n * (2*a + (n - 1)*b) / 2;
    return res;
}

//Geometry---------------------------------------------------------------------------

//line intersection
struct Point
{
    int x;
    int y;
};
  
// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
}
  
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  // collinear
  
    return (val > 0)? 1: 2; // clock or counterclock wise
}
  
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
  
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
  
    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  
     // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  
    return false; // Doesn't fall in any of the above cases
}

int main() {
    fast_io();
    //use ll when possible!
    for (ll n = 1; n <= 24; n++) {
        cout << "n = " << n << " -> " << C(n, 2) << "\n";
    }

    return 0;
}
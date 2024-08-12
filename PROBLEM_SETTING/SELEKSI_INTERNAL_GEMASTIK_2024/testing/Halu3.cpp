#include <bits/stdc++.h>
#define ll long long
#define mn first
#define mx second
using namespace std;

int n; 
int A[200005], B[200005];
pair<int, int> tree[1000005];

void g(int k, int X, int i, int j) {
/*
    k: index of the tree node
    X: element of permutation
    i: index of the bit
    j: index in the array
*/

    if (tree[k].mn == 0) tree[k].mn = j;
    tree[k].mx = max(j, tree[k].mx);
    i--;
    if (i < 0) return;

    int bit = (X & (1 << i)) > 0;
    g((k << 1) + bit, X, i, j);
}

void f(int X, int w, int j) {
    int i = w-1;
    int bit = (X & (1 << i)) > 0;

    if (bit == 0) g(2, X, i, j);
    else g(3, X, i, j);
}

int h(int S, int i, int j, int k, int x, int z) {
/*
    i: current left
    j: current right
    k: bit index
    x: node index
    z: binary path, the best number to xor with S
*/
    
    if (j < i || z > n) return -1;

    if (k == -1) {
        return S ^ z;
    }

    int bit = (S & (1 << k)) > 0;
    // opposite, klo bit == 1 ke kiri, kalau bit == 0 ke kanan
    int opposite = (x << 1) + (1-bit);
    int a = max(i, tree[opposite].mn);
    int b = min(j, tree[opposite].mx);
    int path_1 = (bit ? z : z | (1 << k));
    int A = h(S, a, b, k-1, opposite, path_1);

    if (A != -1) return A;

    // same, klo bit == 1 ke kanan, kalau bit == 0 ke kiri
    int same = (x << 1) + bit;
    int c = max(i, tree[same].mn);
    int d = min(j, tree[same].mx);
    int path_0 = (bit ? z | (1 << k) : z);
    int B = h(S, c, d, k-1, same, path_0);

    return B;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B[i] = A[i];
        B[i] ^= B[i-1];
    }

    int w = __bit_width(n);
    for (int i = 1; i <= n; i++) {
        f(A[i], w, i);
    }

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int L, R; cin >> L >> R;
        int S = B[R] ^ B[L-1];
        int X = h(S, 1, L-1, w-1, 1, 0);
        int Y = h(S, R+1, n, w-1, 1, 0);

        int ans = max(S, max(X, Y));
        cout << ans << "\n";
    }
    
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

int M[105];
tuple<double, int, int> f(int N) {    
    int X = 0;
    int k = 0;
    int mx = 0;
    for (int i = 1; i <= N; i++) {
        if (M[i] > 0) {
            k++;
            X += M[i];
            mx = max(mx, M[i]);
        }
    }

    if (k == 0) return {0, 0, 0};

    return {(double) X / k, k, mx};
}

tuple<int, int> g(int N, double avg, int R) {
    int elite = 0;
    int rare = 0;
    for (int i = 1; i <= N; i++) {
        if (M[i] >= avg) elite++;
        if (M[i] == R) rare++;
    }
    
    return {elite, rare};
}

void h(int N, int X) {
    for (int i = 1; i <= N; i++) {
        if (M[i] > 0) M[i] -= X;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int A, B, R; cin >> A >> B >> R;
    for (int i = 1; i <= N; i++) {
        cin >> M[i];
    }

    int x = 0, y = 0, z = 0;
    while (true) {
        auto [a, k, mx] = f(N);
        if (k == 0) break;
        auto [elite, rare] = g(N, a, R);
        x += elite;
        y += rare;

        if (k == 1 && mx <= B) h(N, B);
        else h(N, A);
        z++;
    }

    cout << x << "\n" << y << "\n" << z << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;

int A[100005];
int B[100005]; // adj

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int x = 99;
    int k = 111;
    for (int i = 1; i <= 100'000'000; i++) {
        x *= x % k;
    }
    for (int i = 1; i <= N; i++) {
        cout << A[i] << "\n";
    }
    
    return 0;
}
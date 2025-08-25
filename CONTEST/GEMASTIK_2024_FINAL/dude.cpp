
#include <bits/stdc++.h>
using namespace std;
 
// Helper: given two positive integers a and b, compute ceil(a/b)
unsigned long long ceilDiv(unsigned long long a, unsigned long long b) {
    return (a + b - 1) / b;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T; 
    cin >> T;
    while(T--){
        // n can be up to 1e12 and A,B up to 1e5.
        unsigned long long n, A, B;
        cin >> n >> A >> B;
 
        // Let x = min(A,B) and d = |A - B|
        unsigned long long x = min(A,B);
        unsigned long long d = (A > B ? A - B : B - A);
 
        // It turns out that if you define
        //    k = ceil( (n*x - 1) / d )
        // then the event (numbering events 0,1,...,n–1) at which they meet again (after the initial meeting at event 0)
        // is ((k-1) mod n) and so the final answer (with 1–based numbering) is
        //    answer = (((k-1) mod n) + 1).
        //
        // (A full derivation is given in the editorial.)
 
        // Compute numerator = n*x - 1 (we work in 128–bit since n*x may be large).
        __int128 numerator = ( (__int128)n * x );
        if(numerator > 0) numerator--; // now numerator = n*x - 1
 
        // Compute k = ceil( (n*x - 1) / d )
        unsigned long long k = ceilDiv((unsigned long long)numerator, d);
 
        // The answer is then ((k-1) mod n) + 1.
        unsigned long long eventIdx = ((k - 1) % n);
        unsigned long long ans = eventIdx + 1;
 
        cout << ans << "\n";
    }
    return 0;
}

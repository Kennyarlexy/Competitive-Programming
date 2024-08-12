#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ull lcm(ull A, ull B) {
    if (A > B) swap(A, B);
    return (A / __gcd(A, B)) * B;
}

int main() {
    fast_io();
    // use ll when possible!
    // using namespace combinatorics;
    // using namespace sequence_series;
    // using namespace num_theory;
    // using namespace geometry;
    // using namespace bitmask;
    // using namespace generator;
    // using namespace graph_theory;
    ull minn, maxx, res1 = 0, res2 = 0; cin >> minn >> maxx;

    ull a,b,c; cin >> a >> b >> c;

    //res1 = maxx/a + maxx/b + maxx/c - maxx/(lcm(a,b)) - maxx/(lcm(b,c)) - maxx/(lcm(a,c)) + maxx / lcm(a,lcm(b,c));
    //res2 = (minn-1)/a + (minn-1)/b + (minn-1)/c - (minn-1)/(lcm(a,b)) - (minn-1)/(lcm(b,c)) - (minn-1)/(lcm(a,c)) + (minn-1) / lcm(a,lcm(b,c));



    ull aa = maxx/a - maxx/lcm(a,b) - maxx/lcm(a,c);
    ull bb = maxx/b - maxx/lcm(b,c) - maxx/lcm(a,b);
    ull cc = maxx/c - maxx/lcm(b,c) - maxx/lcm(a,c);
    ull res3 = aa+bb+cc;

    ull aaa = (minn - 1)/a - (minn-1)/lcm(a,b) - (minn-1)/lcm(a,c);
    ull bbb = (minn-1)/b - (minn-1)/lcm(b,c) - (minn-1)/lcm(a,b);
    ull ccc = (minn-1)/c - (minn-1)/lcm(b,c) - (minn-1)/lcm(a,c);

    ull res4 = aaa+bbb+ccc;

    cout << (ull) res3 - res4 << "\n";

    return 0;
}


// intinya dari range [min, max] cari bilangan yang hanya bisa dibagi A saja, B saja, dan C saja
// maksud A saja, hanya bisa dibagi A, tidak bisa dibagi B ataupun C

// ini lcmnya yang include exclude, cari lcm yang unik, misalnya lcm_unik, terus untuk setiap A, B, C

// [1, 20]
// A = 20 / 9 = 2
// B = 20 / 4 = 5
// C = 20 / 6 = 3
// A + B + C  = 10

// A = 9,18
// B = 4,8,12,16,20
// C = 6,12,18

// res += A - n(lcm(a, b)) - n(lcm(a, c)) + n(lcm(a, b, c))
// res += 2 - 0 - 1 + 0 = 1
// res += B - n(lcm(b, a)) - n(lcm(b, c)) + n(lcm(a, b, c))
// res += 5 - 0 - 1 + 0 = 4
// res += C - n(lcm(c, a)) - n(lcm(c, b)) + n(lcm(a, b, c))
// res += 3 - 1 - 1 + 0 = 1
// 1 + 4 + 1 = 6

// buang 12 dan 18, jadi 10 - 4

// res = A + B + C - unik = 




// myIdea
// A unique = maxx/A - maxx/lcm(a,b) - maxx/lcm(a,c)
// B unique = maxx/B - maxx/lcm(a,b) - maxx/lcm(b,c)
// C unique = maxx/C - maxx/lcm(b,c) - maxx/lcm(a,c)

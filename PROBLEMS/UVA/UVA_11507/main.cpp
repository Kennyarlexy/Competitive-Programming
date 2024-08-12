#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll A[100005];
ll B[100005];

string res[4][4] = {
    {"+x", "+y", "-x", "-y"},
    {"+z", "+y", "-z", "-y"},
    {"-x", "+y", "+x", "-y"},
    {"-z", "+y", "+z", "-y"}
};

int main() {
    fast_io();
    //use ll when possible!
    ll L;
    while (cin >> L && L) {
        ll plane_A = 0, plane_B = 0;
        for (ll j = 1; j < L; j++) {
            string dir; cin >> dir;
            if (dir == "No") continue;
            if (dir == "+y") A[j] = 1;
            else if (dir == "-y") A[j] = -1;
            else if (dir == "+z") B[j] = 1;
            else B[j] = -1;
        }
        
        for (ll j = 1; j < L; j++) {
            string dir; cin >> dir;
            if (dir == "No") continue;
            if (dir == "+y") plane_A;
            else if (dir == "-y") plane_A--;
            else if (dir == "+z") plane_B++;
            else plane_B--;
        }
        

        plane_A = (plane_A + 100000) % 4;
        plane_B = (plane_B + 100000) % 4;
        cout << res[plane_B][plane_A] << "\n";
    }

    return 0;
}
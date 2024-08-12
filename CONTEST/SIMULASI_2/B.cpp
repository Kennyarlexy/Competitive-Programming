#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    string line;
    ll cnt = 0;
    while (getline(cin, line)) {
        for (ll i = 2; i < line.length(); i++) {
            if (line[i-2] == 't' && line[i-1] == 'e' && line[i] == 's'){
                cnt++;
                i += 2; //doesn't change complexity tho, minor optimization, noooo i just takut tc yg SUS wwkwkwk misalnya Stringnya EEEEE, mau nyari EEE jadi sus dia
                // karena tes beda huruf, no need to worry about that // okay Thx just gas udh ketinggalan sm kobokan aer nih wkwkw
            } //AC
            
        }
    }
    cout << cnt << "\n";

    return 0;
}
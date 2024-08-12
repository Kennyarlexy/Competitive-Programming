#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int r, s, t; cin >> r >> s >> t;
        double lingkaran = 3.14 * pow(r, 2);
        double segitiga = 0.5 * s * (0.5 * sqrt(3)) * s;
        double persegi = pow(t, 2);
        vector<double> v = {lingkaran, segitiga, persegi};
        sort(v.begin(), v.end(), greater<double>());
        
        if (v[0] == lingkaran) {
            cout << "LINGKARAN" << endl;
        } else if (v[0] == segitiga) {
            cout << "SEGITIGA" << endl;
        } else {
            cout << "PERSEGI" << endl;
        }
    }
    
    return 0;
}
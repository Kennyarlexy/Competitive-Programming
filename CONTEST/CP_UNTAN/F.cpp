#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    int total = 0, index = 0;
    for (auto &data : v) {
        cin >> data;
        total += data;
    }

    bool possible = false;

    vector<int> belongings(n, 2);
    if (total % 2 == 0) {
        int avg = total / 2, tempTotal = 0;
        //iterate through the vector, try matching the tempTotal with avg
        for (int i = 0; i < n; i++) {
            
            //avg - tempTotal -> the amount that is still lacking
            if (v[i] <= (avg - tempTotal)) {
                tempTotal += v[i];
                belongings[i] = 1;
            }
        }
        possible = (tempTotal == avg ? true : false);
    }

    cout << boolalpha << possible << endl;

    // cout << (possible ? "YA" : "TIDAK") << endl;
    // cout << (total % 2 == 0 ? "YA" : "TIDAK") << endl;
    
    return 0;
}
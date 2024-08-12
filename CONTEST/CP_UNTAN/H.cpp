#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// int FPB(int x, int y) {
//     int num = 0;
//     while (true) {
//         num += fmin(x, y);
//         if (num % x == 0 && num % y == 0) break;
//     }

//     return num;
// }

int main() {
    int x, y, n; cin >> x >> y >> n;

    // int add_boss = (FPB(x, y) / x) + (FPB(x, y) / y);
    int menit = n / ((1.0/x) + (1.0/y));
    int killed_boss = (menit / x) + (menit / y); 
    
    while (killed_boss != n) {
        menit++;
        if (menit % x == 0) {
            killed_boss++;
        } 
        if (menit % y == 0) {
            killed_boss++;
        }
    }
    
    cout << menit << endl;
    
    return 0;
}
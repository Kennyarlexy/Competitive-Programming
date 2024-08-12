#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; 
    cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        int k = b - a + 1;
        int sum = (k/2.0) * (a + b);
        // for (int i = a; i <= b; i++) {
        //     sum += i;
        // }
        cout << sum << endl;
    }

    return 0;
}
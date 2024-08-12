#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p; cin >> n >> p;
    vector<int> v(n);
    int count = 0;
    for (auto &data : v) {
        cin >> data;
        if (data == p) {
            data = -1;
            count++;
        }
    }
    cout << n - count << endl;
    for (int i = 0; i < n; i++) {
        if (v[i] != -1) {
            cout << v[i];
            if (i < n - 1) {
                cout << ' ';
            }
        }
    }
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x; cin >> x;
    string t; cin >> t;
    int temp = stoi(t.substr(0, 2));
    temp = (temp + x) % 24;

    if (temp < 10) {
        t.replace(0, 2, "0" + to_string(temp));
    } else {
        t.replace(0, 2, to_string(temp));
    }
    
    cout << t << endl;
    
    return 0;
}
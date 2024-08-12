#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int T; cin >> T;
    set<char> set = {'a', 'e', 'i', 'o', 'u'};
    for (int t = 1; t <= T; t++) {
        string K; cin >> K;
        char ch = tolower(K[K.length() - 1]);
        cout << "Case #" << t << ": " << K << " is ruled by ";
        if (set.find(ch) != set.end()) {
            cout << "Alice." << endl;
        } else if (ch == 'y') {
            cout << "nobody." << endl;
        } else {
            cout << "Bob." << endl;
        }
    }
    
    return 0;
}
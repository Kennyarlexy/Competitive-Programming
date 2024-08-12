#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1[0] == s2[0]) {
        if (s1[2] == '>') {
            cout << s1[4] << " " << s1[0] << " " << s2[4] << endl;
        } else {
            cout << s2[4] << " " << s1[0] << " " << s1[4] << endl;
        }
    } else if (s1[4] == s2[0]) {
        if (s1[2] == '<') {
            cout << s1[0] << " " << s1[4] << " " << s2[4] << endl;
        } else {
            cout << s2[4] << " " << s1[4] << " " << s1[0] << endl;
        }
    } else if (s1[0] == s2[4]) {
        if (s1[2] == '>') {
            cout << s1[4] << " " << s1[0] << " " << s2[0] << endl;
        } else {
            cout << s2[0] << " " << s1[0] << " " << s1[4] << endl;
        }
    } else {
        if (s1[2] == '>') {
            cout << s2[0] << " " << s1[4] << " " << s1[0] << endl;
        } else {
            cout << s1[0] << " " << s2[4] << " " << s2[0] << endl;
        }
    }
    //line 1
    // char A_line_1, B_line_1, C_line_1; cin >> A_line_1 >> B_line_1 >> C_line_1;

    // char A_line_2, B_line_2, C_line_2; cin >> A_line_2 >> B_line_2 >> C_line_2;

    

    
    return 0;
}
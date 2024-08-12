#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

/*
input citation and group by its number of appearance in input 
Example: 1, 2, 3, 4, 5
1 appearance = 5 --> {1, 5}
2 appearance = 4 --> {2, 4}
3 appearance = 3 --> {3, 3}
...
*/
void input(int C, set<int> &s, vector<vector<int>> &v) {
    if (s.find(C) == s.end()) {
        s.insert(C);
        v.push_back({C, 0});
    } 
    // else {
    for (int j = 0; j < v.size(); j++) {
        if (v[j][0] <= C) {
            v[j][1]++;
        }
    }
    // }
}


int main() {
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {;
        int N; cin >> N;
        
        vector<vector<int>> v;
        set<int> s;
        int check = 1, H = 0;

        //count at least amount of time a citation done for a paper
        for (int i = 0; i < N; i++) {
            int C; cin >> C;
            input(C, s, v);
            int count = 0;
            for (int j = 0; j < v.size(); j++) {
                if (v[j][0] >= check) {
                    count += v[j][1];
                }
            }
            if (count >= check) {
                check++;
                H++;
            }
            if (i == 0) {
                cout << "Case #" << t << ": ";
            }
            cout << H << " ";
        }
        cout << endl;
    }
    
    return 0;
}
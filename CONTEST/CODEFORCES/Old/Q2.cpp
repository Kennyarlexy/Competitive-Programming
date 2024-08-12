#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxV(const vector<int> &vect) {
    int max = 0;
    for (int i = 0; i < vect.size(); i++) {
        max = vect[i] > max ? vect[i] : max;
    }

    return max;
}

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> vect;
        for (int j = 0; j < n; j++) {
            int input; cin >> input;
            vect.push_back(input);
        }
        int max = maxV(vect);
        int count = 0;
        int size = vect.size();
        while (vect[size - 1] < max) {
            vector<int> v1;
            vector<int> v2;
            for (int j = 0; j < size; j++) {
                if (vect[j] <= vect[size - 1]) {
                    v1.push_back(vect[j]);
                } else {
                    v2.push_back(vect[j]);
                }
            }
            merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vect.begin());
            count++;
        }
        cout << count << endl;
    }

    return 0;
}
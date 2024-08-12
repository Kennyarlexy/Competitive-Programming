#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(const vector<int>& vect)
{
    int max = 0;
    for (auto data : vect) {
        if (data > max) {
            max = data;
        }
    }

    return max;
}

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> vect;
        for (int j = 0; j < n; j++) {
            int input; cin >> input;
            vect.push_back(input);
        }
        int max = getMax(vect);
        int step = 0;
        int temp = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (vect[j] == max) {
                break;
            }
            if (vect[j] > temp) {
                temp = vect[j];
                step++;
            }
        }
        cout << step << endl;
    }

    return 0;
}
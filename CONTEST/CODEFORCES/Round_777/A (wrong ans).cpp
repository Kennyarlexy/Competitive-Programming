#include <bits/stdc++.h>
using namespace std;

string getPossible(int target) {
    string possible;
    int start = 0;
    int sum = 0;
    while (true) {
        int digit = start % 9 + 1;
        sum += digit;
        if (sum > target) {
            sum -= digit;
            break;
        }

        possible += to_string(digit);
        start++;
    }
    if (sum < target) possible += to_string(target - sum);

    if (possible.length() == 2 && possible[0] == possible[1]) {
        possible = (possible[0]-'0') + (possible[1]-'0') + '0';
    }

    return possible;
}

int getInvalid(string possible) {
    int invalid = 0;
    for (int i = 1; i <= possible.length(); i += 1) {
        if (possible[i] == possible[i-1]) {
            invalid = i;
            break;
        }
    }
    return invalid;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int target; cin >> target;
        string possible = getPossible(target);

        sort(possible.begin(), possible.end(), greater<char>());
        string max = possible;
        int invalidLoc = getInvalid(max);
        if (invalidLoc > 0) {
            if (invalidLoc == max.length() - 1) {
                char temp = max[invalidLoc-1];
                max[invalidLoc-1] = max[invalidLoc-2];
                max[invalidLoc-2] = temp;
            } else {
                char temp = max[invalidLoc];
                max[invalidLoc] = max[invalidLoc+1];
                max[invalidLoc+1] = temp;
            }
        }
        cout << max << "\n";
    }
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

bool canDefeatBoss(const vector<int>& powers, const vector<int>& speeds, long long hp, int time) {
    long long totalDamage = 0;
    for (int i = 0; i < 4; i++) {
        int attacks = time / speeds[i];
        if (time % speeds[i] != 0)
            attacks++;
        totalDamage += static_cast<long long>(attacks) * powers[i];
    }
    return totalDamage >= hp;
}

int main() {
    vector<int> powers(4);
    vector<int> speeds(4);
    long long bossHP;

    for (int i = 0; i < 4; i++) {
        cin >> powers[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> speeds[i];
    }

    cin >> bossHP;

    // Binary search for the time to defeat the boss
    int left = 0;
    int right = 2e9; // Arbitrarily large value, can be adjusted based on constraints
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canDefeatBoss(powers, speeds, bossHP, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}

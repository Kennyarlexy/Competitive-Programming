#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> sisik(n);
    for (int i = 0; i < n; i++) {
        cin >> sisik[i];
    }

    sort(sisik.begin(), sisik.end());

    vector<int> hasil;
    for (int i = 0; i < n; i++) {
        if (isEven(i) && !isEven(sisik[i])) {
            hasil.push_back(sisik[i]);
        }
        else if (!isEven(i) && isEven(sisik[i])) {
            hasil.push_back(sisik[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if ((isEven(i) && isEven(sisik[i])) || (!isEven(i) && !isEven(sisik[i]))) {
            hasil.push_back(sisik[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << hasil[i] << " ";
    }

    return 0;
}

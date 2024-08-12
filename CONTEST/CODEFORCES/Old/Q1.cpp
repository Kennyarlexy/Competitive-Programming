#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        int arr[n];
        int h = 1;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if (j >= 1) {
                if (arr[j] == 0 && arr[j - 1] == 0) {
                    h = -1;
                    string str;
                    getline(cin, str);
                    cin.clear();
                    break;
                } else if (arr[j] == 1 && arr[j - 1] == 1) {
                    h += 5;
                } else if (arr[j] == 1 && arr[j - 1] == 0) {
                    h += 1;
                }
            } else if (j == 0) {
                if (arr[j] == 1) {
                    h += 1;
                }
            }
        }
        cout << h << endl;
    }


    return 0;
}
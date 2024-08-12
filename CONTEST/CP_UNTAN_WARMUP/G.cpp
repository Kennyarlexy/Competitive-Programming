#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            //3, 7, 10 -> 4, 8, 11
            if (arr[i] % 2 == 1 && arr[i-1] % 2 == 1) {
                arr[i-1] += 1;
                arr[i] += 1;
                arr[i+1] += 1;
            }
        }   
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M; cin >> N >> M;

        int total = 0;
        for (int i = 0; i < N; i++) {
            int temp; cin >> temp;
            total += temp;
        }
        cout << "Case #" << t + 1 << ": " << total % M << endl;
        
    }
    
    return 0;
}
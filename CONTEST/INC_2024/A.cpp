#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

string A[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 1;i <= N; i++) {
        cin >> A[i];
    }

    set<char> S = {'a', 'o', 'u'};
    set<char> S2 = {'a', 'i', 'u', 'e', 'o'};
    set<char> S3 = {'h', 'y'};
    set<char> S4 = {'e', 'i', 'y'};
    for (int i = 1; i <= N; i++) {
        int n = A[i].length();
        if (A[i][n-1] == 'c') A[i][n-1] = 'k';

        for (int j = 0; j < n-1; j++) {
            if (A[i][j] == 'c' && A[i][j+1] == 'h') {
                A[i][j+1] = '.';
            } else if (A[i][j] == 'c') {
                if (S.count(A[i][j+1]) || (S2.count(A[i][j+1]) == 0 && S3.count(A[i][j+1]) == 0)) A[i][j] = 'k';
                else if (S4.count(A[i][j+1])) A[i][j] = 's';
            } 
        }

        for (int j = 0; j < n; j++) {
            if (A[i][j] == '.') continue;
            cout << A[i][j];
        }
        cout << "\n";
    }
    
    
    return 0;
}
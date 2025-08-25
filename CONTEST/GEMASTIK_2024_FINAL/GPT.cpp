#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string S, T;
    cin >> S >> T;
    
    // dp[i][j] = length of SCS for S[i:] and T[j:]
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // Base cases:
    for (int i = n; i >= 0; i--){
        for (int j = m; j >= 0; j--){
            if(i == n && j == m){
                dp[i][j] = 0;
            }
            else if(i == n){
                dp[i][j] = m - j;
            }
            else if(j == m){
                dp[i][j] = n - i;
            }
            else if(S[i] == T[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    
    // Reconstruct the SCS string:
    string ans = "";
    int i = 0, j = 0;
    while(i < n || j < m){
        if(i == n){
            // S is exhausted; add remaining T
            ans.push_back(T[j]);
            j++;
        }
        else if(j == m){
            // T is exhausted; add remaining S
            ans.push_back(S[i]);
            i++;
        }
        else if(S[i] == T[j]){
            // Both characters are equal: choose that and move both pointers
            ans.push_back(S[i]);
            i++; j++;
        }
        else{
            // Characters differ; decide based on dp values
            int option1 = dp[i+1][j];
            int option2 = dp[i][j+1];
            if(option1 < option2){
                ans.push_back(S[i]);
                i++;
            }
            else if(option2 < option1){
                ans.push_back(T[j]);
                j++;
            }
            else{
                // Equal dp value: choose lexicographically smaller character
                if(S[i] <= T[j]){
                    ans.push_back(S[i]);
                    i++;
                } else {
                    ans.push_back(T[j]);
                    j++;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}

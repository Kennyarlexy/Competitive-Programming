#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> get_lcs_indices(const string& S, const string& T) {
    int n = S.size(), m = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i-1] == T[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<pair<int, int>> indices;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (S[i-1] == T[j-1]) {
            indices.emplace_back(i-1, j-1);
            --i; --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else if (dp[i-1][j] < dp[i][j-1]) {
            --j;
        } else {
            // When there's a tie, prefer moving left to capture earlier characters in T
            --j;
        }
    }
    reverse(indices.begin(), indices.end());
    return indices;
}

string merge(string a, string b) {
    string result;
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (i < a.size() && (j >= b.size() || a[i] <= b[j])) {
            result += a[i++];
        } else {
            result += b[j++];
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    auto lcs_indices = get_lcs_indices(S, T);

    if (lcs_indices.empty()) {
        cout << merge(S, T) << '\n';
        return 0;
    }

    string U;

    // Pre-parts
    int s0 = lcs_indices[0].first;
    int t0 = lcs_indices[0].second;
    string s_pre = S.substr(0, s0);
    string t_pre = T.substr(0, t0);
    U += merge(s_pre, t_pre);
    U += S[s0];

    // Middle parts
    for (int i = 1; i < lcs_indices.size(); ++i) {
        int s_prev = lcs_indices[i-1].first;
        int t_prev = lcs_indices[i-1].second;
        int s_curr = lcs_indices[i].first;
        int t_curr = lcs_indices[i].second;

        string s_part = S.substr(s_prev + 1, s_curr - s_prev - 1);
        string t_part = T.substr(t_prev + 1, t_curr - t_prev - 1);

        U += merge(s_part, t_part);
        U += S[s_curr];
    }

    // Post-parts
    int s_last = lcs_indices.back().first;
    int t_last = lcs_indices.back().second;
    string s_post = S.substr(s_last + 1);
    string t_post = T.substr(t_last + 1);
    U += merge(s_post, t_post);

    cout << U << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt_x, cnt_y;
map<int, map<int, int>> cnt_xy;
int X[5005];
int Y[5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
        cnt_x[X[i]]++;
        cnt_y[Y[i]]++;
        cnt_xy[X[i]][Y[i]]++;
    }

    int best_x_axis = 0;
    int best_x_axis_cnt = 0; 
    for (int i = 1; i <= n; i++) {
        if (cnt_x[X[i]] > best_x_axis_cnt) {
            best_x_axis = X[i];
            best_x_axis_cnt = cnt_x[X[i]];
        }
    }

    int best_y_axis = 0;
    int best_y_axis_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt_y[X[i]] > best_y_axis_cnt) {
            best_y_axis = X[i];
            best_y_axis_cnt = cnt_y[X[i]];
        }
    }

    int max = 0;
    int max_x, max_y;
    for (int i = 1; i <= n; i++) {
        int sum = best_x_axis_cnt + cnt_y[Y[i]] - cnt_xy[best_x_axis][Y[i]];
        if (sum > max) {
            max_x = best_x_axis;
            max_y = Y[i];
            max = sum;
        }
    }
    

    for (int i = i; i <= n; i++) {
        int sum = cnt_x[X[i]] + best_y_axis_cnt - cnt_xy[X[i]][best_y_axis];
        if (sum > max) {
            max_x = X[i];
            max_y = best_y_axis;
            max = sum;
        }
    }

    cout << max << "\n";
    cout << max_x << " " << max_y << "\n";
    
    return 0;
}

/*
9
1 1
1 1
1 1
1 1
1 1
2 1
1 2
0 2
0 3
*/
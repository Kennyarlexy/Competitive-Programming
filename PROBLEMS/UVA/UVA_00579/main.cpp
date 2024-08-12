#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    double H, M;
    while (true) {
        scanf("%lf:%lf", &H, &M);
        if (H == 0 && M == 0) break;

        double degM = M*6;
        double degH = H*30 + M/2;
        if (degH >= 360) degH -= 360;

        double diff = abs(degH - degM);
        printf("%.3lf\n", min(diff, 360-diff));
    }
    
    return 0;
}
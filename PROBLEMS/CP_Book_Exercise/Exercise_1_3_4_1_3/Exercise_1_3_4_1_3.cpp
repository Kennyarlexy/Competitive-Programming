#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    fast_io();
    //use ll when possible!
    ll d, y; string m;
    cin >> d >> m >> y;
    string days_name[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    ll days = (y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400;
    bool leap_year = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    pair<string, ll> days_in_month[] = {{"January", 31}, {"February", (leap_year ? 29 : 28)}, {"March", 31}, {"April", 30}, {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31}, {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}};
    for (ll i = 0; i < 12 && m != days_in_month[i].f; i++) days += days_in_month[i].s;
    cout << days_name[(days+d) % 7] << "\n";
    
    return 0;
}
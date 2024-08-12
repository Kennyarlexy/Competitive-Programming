#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n; ll arr[n];

    set<ll> q;

    for(ll i = 0; i < n; i++){
        ll temp; cin >> temp;
        q.insert(temp);
    }

    q.insert(LLONG_MAX);
    sort(arr, arr+n);

    ll prev = *q.begin();
    ll start = prev;
    ll enn = prev;

    vector<string> res;

    auto itr = ++q.begin();

    for(; itr != q.end(); ++itr){
        ll now = *itr;
        if(now-1==prev){
            enn=now;
        }

        else{
            string str;

            if(start==enn) str = to_string(start);
            else str = to_string(start) + "-" + to_string(enn);

            res.push_back(str);
            start = now;
            enn=now;
        }
        prev = now;

    }

    for(ll i = 0; i < res.size(); i++){
        cout << res[i];
        if(i!=res.size()-1) cout << ",";
    }
    cout << "\n";
    return 0;
}
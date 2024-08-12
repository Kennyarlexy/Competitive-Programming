#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<string, string> t1;
unordered_map<string, string> t2;
void gen(){
    t1["AB"] = "AA";
    t1["DC"] = "AB";
    t1["CC"] = "AC";
    t1["CB"] = "AD";
    t1["CA"] = "BA";
    t1["DA"] = "BB";
    t1["CD"] = "BC";
    t1["DD"] = "BD";
    t1["BC"] = "CA";
    t1["AA"] = "CB";
    t1["BA"] = "CC";
    t1["DB"] = "CD";
    t1["BD"] = "DA";
    t1["AD"] = "DB";
    t1["BB"] = "DC";
    t1["AC"] = "DD";

    t2["CD"] = "AA";
    t2["BB"] = "AB";
    t2["AC"] = "AC";
    t2["CC"] = "AD";
    t2["CB"] = "BA";
    t2["DB"] = "BB";
    t2["AD"] = "BC";
    t2["DD"] = "BD";
    t2["DA"] = "CA";
    t2["DC"] = "CB";
    t2["BC"] = "CC";
    t2["BD"] = "CD";
    t2["AA"] = "DA";
    t2["BA"] = "DB";
    t2["CA"] = "DC";
    t2["AB"] = "DD";
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    gen();
    string str; cin >> str;

    for(ll i = 0; i < str.length(); i+=2){
        string temp = string(1, str[i]) + string(1, str[i+1]);
        cout << t1[t2[temp]];
    }
    cout << "\n";
    return 0;
}

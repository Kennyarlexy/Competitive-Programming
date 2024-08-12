#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

//type 1 -> +
//type 2 -> *

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N; cin >> N;
        map<string, pair<string, ll>> MP;
        //                       ^type
        string A[6];
        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= 5; j++) {
                cin >> A[j];
            }

            if (A[4] == "+") {
                if (!isdigit(A[5][0])) {
                    string temp = MP[A[5]].fi;
                    if (MP[A[5]].se == 1) {
                        temp.insert(0, "(");
                        temp.push_back(')');
                    }
                    A[5] = temp;
                }
                if (!isdigit(A[3][0])) {
                    A[3] = MP[A[3]].fi;
                }

                MP[A[1]] = {A[3]+A[4]+A[5], 1};
            } else if (A[4] == "*") {
                if (!isdigit(A[3][0])) {
                    string temp = MP[A[3]].fi;
                    if (MP[A[3]].se == 1) {
                        temp.insert(0, "(");
                        temp.push_back(')');
                    }
                    A[3] = temp;
                }
                if (!isdigit(A[5][0])) {
                    string temp = "(";
                    temp += MP[A[5]].fi;
                    temp += ")";
                    A[5] = temp;
                }
                MP[A[1]] = {A[3]+A[4]+A[5], 2};
            }
        }
        cout << "Expression #" << t << ": " << MP[A[1]].fi << "\n";
    }
    
    return 0;
}
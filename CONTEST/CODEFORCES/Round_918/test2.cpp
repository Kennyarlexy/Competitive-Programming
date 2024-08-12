#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll global_variable = 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll local_variable = 100;

    auto function_1 = [&] () {
        auto function_2 = [&] () {
            local_variable *= 100;
        };
        function_2();
    };

    function_1();
    cout << local_variable << "\n";
    
    return 0;
}
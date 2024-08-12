#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    // fast_io();
    //use ll when possible!
    ll T; cin >> T;
    for (ll t = 1; t <= T; t++) {
        string A, B; cin >> A >> B;
        deque<char> hand_A, hand_B;

        for (ll i = 0; i < A.length(); i++) {
            hand_A.push_back(A[i]);
            hand_B.push_back(B[i]);
        }

        deque<char> pile_A, pile_B;
        ll round = 0;
        while (++round <= 1000 ) {
            if (hand_A.empty()) {
                hand_A = pile_A; pile_A = {};
                reverse(hand_A.begin(), hand_A.end());
            }
            if (hand_B.empty()) {
                hand_B = pile_B; pile_B = {};
                reverse(hand_B.begin(), hand_B.end());
            }

            pile_A.push_front(hand_A.front()); hand_A.pop_front();
            pile_B.push_front(hand_B.front()); hand_B.pop_front();
            if (pile_A.front() == pile_B.front()) {
                ll who; cin >> who;
                // if (random()/141%2 == 0) {
                if (who == 0) {
                    while (!pile_B.empty()) {
                        pile_A.push_front(pile_B.back());
                        pile_B.pop_back();
                    }
                    cout << "Snap! for Jane: ";
                    for (auto& card : pile_A) {
                        cout << card;
                    }
                    cout << "\n";
                    if (hand_B.empty()) {
                        cout << "Jane wins.\n";
                        break;
                    }
                    
                } else {
                    while (!pile_A.empty()) {
                        pile_B.push_front(pile_A.back());
                        pile_A.pop_back();
                    }
                    cout << "Snap! for John: ";
                    for (auto& card : pile_B) {
                        cout << card;
                    }
                    cout << "\n";
                    if (hand_A.empty()) {
                        cout << "John wins.\n";
                        break;
                    }
                }
            }
        }
        if (round > 1000) cout << "Keeps going and going ...\n";
        if (t < T) cout << "\n";
    }

    return 0;
}
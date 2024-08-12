#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> jml_kemunculan;
    for (int i = 0; i < n; i++) {
        int kelopak;
        cin >> kelopak;
        jml_kemunculan[kelopak]++;
    }

    int maks = -1;
    for (int i = 3; i < 6; i++) {
        if (jml_kemunculan[i] > maks)
            maks = jml_kemunculan[i];
    }

    vector<int> output;
    for (int i = 3; i < 6; i++) {
        if (jml_kemunculan[i] == maks) 
            output.push_back(i);
    }

    sort(output.begin(), output.end(), greater<int> ());
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    
    return 0;
}
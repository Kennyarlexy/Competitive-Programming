#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, e, count = 0, sum = 0;
	cin >> n >> e;
	vector<int>v;

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (c < 7)
			v.push_back(c);
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > e) {
			continue;
		} else if (sum >= e) {
			break;
		} else if (v[i] == e) {
			sum += v[i];
			count++;
		} else {
			sum += v[i];
			count++;
		}
	}
    
	cout << count << endl;

	return 0;
}
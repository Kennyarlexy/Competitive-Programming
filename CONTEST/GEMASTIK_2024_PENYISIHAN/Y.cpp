#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> n;
	int a, b, c, count = 0, sum = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> c;
		if (c < 7) {
			n.push_back(c);
		}
	}
	sort(n.begin(), n.end(), greater <int> ());
	for (int i = 0; i < n.size(); i++) {
		//cout << n[i] << " ";
		if (n[i] > b) {
			continue;
		}
		if (n[i] == b) {
			sum += n[i];
			count++;

		} else {
			sum += n[i];
			count++;

		}
		if (sum >= b)
			break;
	}
	//cout << "\n";
	cout << count << "\n";

	return 0;
}
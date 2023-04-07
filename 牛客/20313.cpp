#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define int long long
signed main() {
	int n; cin >> n;
	if (n == 1) { cout << 0; return 0; }
	unordered_set<float>s;
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			s.insert(j * 1.0 / i);
		}
	}
	cout << s.size() * 2 + 3;
	return 0;
}

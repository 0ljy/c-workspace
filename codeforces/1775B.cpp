#include<bits/stdc++.h>
#include<unordered_map>
#include<chrono>
using namespace std;
#define int long long 
#define quick std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
vector<int>a[100005];
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
void solve() {
	unordered_map<int, int>m;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)a[i].clear();
	int x;
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> x;
			a[i].push_back(x);
			m[x]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		int la = 0;
		for (auto it : a[i]) {
			if (m[it] >= 2) ++la;
		}
		if (la == (int)a[i].size()) { cout << "YES\n"; return; }
	}
	cout << "NO\n";
}
signed main() {
	quick;
	int t; cin >> t;
	while (t--)solve();
	return 0;
}
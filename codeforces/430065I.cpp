#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<int,int>f,sz;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void me(int a, int b) {
	if (!f.count(a)) { f[a] = a; sz[a] = 1; }
	if (!f.count(b)) { f[b] = b; sz[b] = 1; }
	int fa = find(a), fb = find(b);
	if (fa == fb)return;
	f[fb] = fa;
	sz[fa] += sz[fb];
	return;
}
void solve() {
	f.clear();
	sz.clear();
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		me(a, b);
	}
	int mx = 1;
	for (unordered_map<int, int>::iterator it = f.begin(); it != f.end();++it) {
		if (it->first==it->second)mx = max(mx, sz[it->first]);
	}
	cout << mx << '\n';
	return;
}
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}
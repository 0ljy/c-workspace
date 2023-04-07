#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
const int N = 5e5 + 5;
int n, m;
vector<int>a(N, 0);
vector<int>c(N, 0);
int lowbit(int x) {
	return x & (-x);
}
//初始化
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += lowbit(j)) {
			c[j] += a[i];
		}
	}
	return;
}
//点修改
void add(int i, int k) {
	a[i] += k;
	for (; i <= n; i += lowbit(i))c[i] += k;
	return;
}
//求前缀和
int sum1(int i) {
	int sum = 0;
	for (; i > 0; i -= lowbit(i))sum += c[i];
	return sum;
}
//求区间和
int sum2(int i, int j) {
	return sum1(j) - sum1(i - 1);
}
signed main() {
	quick;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	init();
	int op, x, y;
	while (m--) {
		cin >> op >> x >> y;
		if (op == 1) {
			add(x, y);
		}
		else {
			cout << sum2(x, y) << '\n';
		}
	}
	return 0;
}
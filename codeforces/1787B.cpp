#include<bits/stdc++.h>
#include<ctime>
using namespace std;
#define int long long
signed main() {
	std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int m; cin >> m;
		if (m % 2 == 1) { cout << m << '\n'; continue; }
		int a[1000] = { 0 };
		int b[100] = { 0 };
		int i = 0;
		int j = 0, n = 0;
		int k1[1000] = { 0 }, k2[1000] = { 0 };
		int k = 0;
		for (i = 2; i <= m; i++) {
			int fk = 0;
			n = sqrt(i);
			//				对每一个数 i 分解它的素数 
			while (m % i == 0) {
				for (j = 2; j < n; j++) {
					if (i % j == 0) {
						break;
					}
				}
				if (j >= n) {
					//						i为素数，则保存到数组中
					a[k] = i;
					k++;
				}
				m /= i;
			}
		}
		int x = 0;
		int flag = 0;
		for (i = 0; i < k; i++) {
			x = 0;
			for (j = i; j < k; j++) {
				if (a[i] == a[j])
					x++;
			}
			i = i + x - 1;
			k1[flag] = a[i];
			k2[flag++] = x;
		}
		if (flag == 2) {
			int aa = min(k2[0], k2[1]);
			int kk = 0;
			if (k2[0] < k2[1])swap(k1[0], k1[1]);
			int ans = k1[0] * k1[1] * aa + (max(k2[0], k2[1]) - aa) * k1[0];
			cout << ans << '\n';
		}
		else {
			int ans = 0;
			int kkk = 0;
			int mid = 1;
			while (1) {
				mid = 1;
				kkk = 0;
				int mins = INT_MAX;
				for (int i = 0; i < flag; ++i) {
					if (k2[i] != 0) {
						mid *= k1[i];
						mins = min(mins, k2[i]);
					}
				}
				for (int i = 0; i < flag; ++i) {
					if (k2[i] != 0)k2[i] -= mins;
					if (k2[i] != 0)++kkk;
				}
				ans += mid * mins;
				if (kkk <= 1) {
					for (int i = 0; i < flag; ++i) {
						if (k2[i] != 0)ans += k1[i] * k2[i];
					}
					cout << ans << '\n';
					goto A;
				}
			}
		}
	A:;
	}
	return 0;
}
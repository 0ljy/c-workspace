#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr);
string a;
signed main() {
	quick;
	int t; cin >> t;
	while (t--) {
		cin >> a;
		int len = a.size();
		int flag = 0;
		for (int i = 1; i < len - 1; ++i) {
			if (a[i] == 'a') {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << a[0];
			for (int i = 1; i < len; ++i) {
				if (a[i] == 'b')cout << a[i];
				else {
					cout << ' ';
					cout << a[i] << ' ';
					for (int j = i + 1; j < len; ++j)cout << a[j];
					cout << '\n';
					goto END;
				}
			}
		}
		else {
			cout << a[0] << ' ';
			for (int i = 1; i < len - 1; ++i)cout << a[i];
			cout << ' ' << a[len - 1] << '\n';
		}
	END:;
	}
	return 0;
}
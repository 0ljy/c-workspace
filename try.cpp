#include<bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
    int s=a+b;
    int kk=sqrt(s);
    int ans=(s+kk)/(kk+1)+kk;
    kk++;
    ans=min(ans,(s+kk)/(kk+1)+kk);
    cout<<ans<<'\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--)solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a, b; cin >> a >> b;
	//�������Լ��
	//�������Լ����a,b�еĽ�С������
	cout << min(a, b) * (max(a, b) / __gcd(a, b));
	return 0;
}
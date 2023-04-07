#include<bits/stdc++.h>
using namespace std;
const int MAXN(1e5 + 10);
int c[MAXN]; // 树状数组 
int a[MAXN]; // 原数组
int n;
// 用于判断树状数组 的 管理范围 
int lowbite(int i){
    return (-i) & i;
}
// 初始化
void init(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += lowbite(j))
            c[j] += a[i];
    }
    return;
}

//  单点修改函数 
void add(int i, int z){
    a[i] += z;
    for (; i <= n; i += lowbite(i))
        c[i] += z;

}
// 求到达某节点的 前缀和函数 
int sum1(int i){
    int sum = 0;
    for (; i > 0; i -= lowbite(i)) {
        sum += c[i];
    }
    return sum;
}
// 求区间和 
int sum2(int i, int j){
    return sum1(j) - sum1(i - 1);
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    int k;
    cin >> k;
    cout << "前K个值和为: " << sum1(k) << endl;
    int x, y;
    cin >> x >> y;
    cout << "X 到 Y区间和为：" << sum2(x, y) << endl;
}
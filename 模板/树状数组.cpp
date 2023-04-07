#include<bits/stdc++.h>
using namespace std;
const int MAXN(1e5 + 10);
int c[MAXN]; // ��״���� 
int a[MAXN]; // ԭ����
int n;
// �����ж���״���� �� ����Χ 
int lowbite(int i){
    return (-i) & i;
}
// ��ʼ��
void init(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += lowbite(j))
            c[j] += a[i];
    }
    return;
}

//  �����޸ĺ��� 
void add(int i, int z){
    a[i] += z;
    for (; i <= n; i += lowbite(i))
        c[i] += z;

}
// �󵽴�ĳ�ڵ�� ǰ׺�ͺ��� 
int sum1(int i){
    int sum = 0;
    for (; i > 0; i -= lowbite(i)) {
        sum += c[i];
    }
    return sum;
}
// ������� 
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
    cout << "ǰK��ֵ��Ϊ: " << sum1(k) << endl;
    int x, y;
    cin >> x >> y;
    cout << "X �� Y�����Ϊ��" << sum2(x, y) << endl;
}
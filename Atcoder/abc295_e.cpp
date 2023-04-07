#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,k;
int sum;
void extend_gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return;
    }
    extend_gcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
int mod_inverse(int a){
    int x, y;
    extend_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}
void solve(vector<int>a,int i){
    a[k]=i;
    sort(a.begin(),a.end());
    sum+=a[k];
}
vector<int>s;
signed main(){
    cin>>n>>m>>k;
    --k;
    int x;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        s.emplace_back(x);
    }
    for(int i=1;i<=m;++i){
        solve(s,i);
    }
    cout<<(sum* mod_inverse(m))%mod;

    return 0;
}
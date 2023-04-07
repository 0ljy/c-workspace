#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    for(int i=0;i<t;++i){
        int n,m;cin>>n>>m;
        int ans=0;
        int a[200005]={0};
        for(int j=0;j<n;++j)cin>>a[i];
        for(int j=m;j>0;--j){
            if(a[i]<0){ans++;}
        }
        cout<<ans<<'\n';
    }
    return 0;
}
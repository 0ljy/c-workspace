#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[1005];
unordered_map<string,int>hash_map;
void solve(){
    int m,n,a,b;
    cin>>m>>n>>a>>b;
    for(int i=0;i<m;++i){
        cin>>s[i];
    }
    for(int i=0;i<m-a+1;++i){
        for(int j=0;j<n-b+1;++j){
            string mid;
            int mk=1<<6,flag=5;
            for(int k=i;k<i+a;++k){
                for(int l=j;l<j+b;++l){
                    mk|=((int)(s[k][l]-'0')<<flag);
                    --flag;
                    if(flag==0){
                        mid+=(char)mk;
                        mk=1<<6;
                        flag=5;
                    }
                }
            }
            mid+=(char)mk;
            hash_map[mid]=1;

        }
    }
    int c;
    cin>>c;
    string x;
    while(c--){
        string mid;
        int flag=5;
        int mk=1<<6;
        for(int i=0;i<a;++i){
            cin>>x;
            for(int j=0;j<b;++j){
                mk|=((int)(x[j]-'0')<<flag);
                --flag;
                if(flag==0){
                    mid+=(char)mk;
                    mk=1<<6;
                    flag=5;
                }
            }
        }
        mid+=(char)mk;
        if(hash_map.count(mid))cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t=1;
    while(t--)solve();
    return 0;
}
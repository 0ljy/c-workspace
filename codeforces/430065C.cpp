#include<bits/stdc++.h>
using namespace std;
#define int long long
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
char x[1005][1005];
unordered_map<string,int>m;
signed main(){
    quick;
    int t;cin>>t;
    while(t--){
        m.clear();       
        int n,b;cin>>n>>b;
        string s;
        int va=0;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>x[i][j];
        for(int i=0;i<b;++i){cin>>s>>va;m[s]=va;}
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(x[i][j]=='#')continue;
                string xa,xb;
                int ki=i,kj=j;
                if(x[i-1][j]!='\0'&&x[i-1][j]!='#')goto B;
                while(ki<=n&&kj<=n&&x[ki][kj]!='#'){
                    xa+=x[ki][kj];
                    ++ki;
                }
                if(m.count(xa))ans+=m[xa];
                else {cout<<"-1\n";goto A;}
                B:;
                if(x[i][j-1]!='\0'&&x[i][j-1]!='#')goto C;
                ki=i,kj=j;
                while(ki<=n&&kj<=n&&x[ki][kj]!='#'){
                    xb+=x[ki][kj];
                    ++kj;
                }
                if(m.count(xb))ans+=m[xb];
                else {cout<<"-1\n";goto A;}
                C:;
            }
        }
        cout<<ans<<'\n';
        A:;
    }

    return 0;
}
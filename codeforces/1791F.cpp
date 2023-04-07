//TLE
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// vector<int>v;
// int fact(int x){
//     int sum=0;
//     while(x){
//         sum+=x%10;
//         x/=10;
//     }
//     return sum;
// }
// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--){
//         int n,q;cin>>n>>q;
//         v.clear();
//         vector<pair<int,int>>a;
//         int x;
//         for(int i=0;i<n;++i)cin>>x,v.emplace_back(x);
//         for(int i=0;i<q;++i){
//             cin>>x;
//             if(x==1){
//                 int l,r;cin>>l>>r;
//                 a.push_back({l,r});
//             }else{
//                 cin>>x;
//                 int f=0;
//                 for(auto i:a)if(i.first<=x and i.second>=x)++f;
//                 if(f>3)f=3;
//                 int dx=v[x-1];
//                 if(f>=1)dx=fact(v[x-1]);
//                 --f;
//                 while(f>0){
//                     dx=fact(dx);
//                     --f;
//                 }
//                 cout<<dx<<'\n';
//             }
//         }
//     }
//     return 0;
// }


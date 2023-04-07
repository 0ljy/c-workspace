#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define int long long
vector<int>a;
unordered_set<int>s[100005];
int dig[100005];
int n, m;
bool check() {
    for (int i = 2; i <= m; ++i) {
        if (dig[i] == 0)return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        a.clear();
        memset(dig, 0, sizeof(dig));
        cin >> n >> m;
        for (int i = 0; i < n + 1; ++i)s[i].clear();
        int x;
        for (int i = 0; i < n; ++i) { cin >> x; a.emplace_back(x); }
        sort(a.begin(), a.end());
        int k = -1;
        for (auto i : a) {
            ++k;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    s[k].insert(j);
                    s[k].insert(i / j);
                    dig[j]++;
                    if (j != i / j)dig[i / j]++;
                }
            }
        }
        int l = 0, r = n - 1;
        int ans = INT_MAX;
        int kl = 0, kr = n - 1;
        while (l <= r) {
            if (l == r and check()) { cout << "0\n"; goto A; }
            for (auto i : s[l])dig[i]--;
            if (check()) { ++l; ans = min(ans, a[r] - a[l]); }
            else for (auto i : s[l])dig[i]++;
            if (l == r and check()) { cout << "0\n"; goto A; }
            for (auto i : s[r])dig[i]--;
            if (check()) { --r; ans = min(ans, a[r] - a[l]); }
            else for (auto i : s[r])dig[i]++;
            if (l == kl and r == kr)break;
            kl = l, kr = r;
        }
        if (!check())cout << "-1\n";
        else cout << ans << '\n';
    A:;
    }
    return 0;
}
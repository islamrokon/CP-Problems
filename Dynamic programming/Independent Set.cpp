#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
const int N = 1e5+5, mod = 1e9+7;
ll dp[N][2];
vector<int>vec[N];
void dfs(int u, int p)
{
    dp[u][0] = 1;
    dp[u][1] = 1;
    for(auto v : vec[u])
    {
        if(v != p)
        {
            dfs(v,u);
            dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
            dp[u][1] = 1LL * dp[u][1] * dp[v][0] % mod;
        }
    }
}
void solve()
{
    int n, u, v;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0);
    cout << (dp[1][0]+dp[1][1])%mod;
}
int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
}

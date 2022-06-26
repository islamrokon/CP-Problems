#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX ((int)1e9+5)
using namespace std;
vector<int>vec[100005];
int dp[100005];
bool vis[100005];
int dfs(int i)
{
    if(dp[i]!=-1) return dp[i];
    int ans=0;
    for(auto a: vec[i])
    {
        ans=max(ans,1+dfs(a));
    }
    return dp[i]=ans;
}
void solve()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
    }
    memset(dp,-1,sizeof dp);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        ans=max(ans,dfs(i));
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

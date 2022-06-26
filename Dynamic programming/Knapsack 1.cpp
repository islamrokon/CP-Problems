#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e9+5
using namespace std;
ll n,w,dp[105][100005],a[105],b[105];
ll rec(ll i, ll val)
{
    if(val>w) return -MAX;
    if(i==n+1) return 0;
    if(dp[i][val]!=-1) return dp[i][val];
    ll ans=rec(i+1,val);
    if(val+a[i]<=w) ans=max(ans,b[i]+rec(i+1,val+a[i]));
    return dp[i][val]=ans;
}
void solve()
{
    cin>>n>>w;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<rec(1,0);
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

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
int n,w,dp[105][100005],a[105],b[105];
int rec(int i, int pro) ///but recursion is based on index and profit.
{
    if(pro<=0) return 0; ///profit is internal but ultimaltely weight will be returned.
    if(i>n){
        if(pro>0)
            return MAX;
        else return 0;
    }
    if(dp[i][pro]!=-1) return dp[i][pro];
    int ans=MAX;
    ans=rec(i+1,pro); ///not adding weight
    int rem=pro-b[i];
    ans=min(ans,rec(i+1,rem)+a[i]); ///here we are adding minimum weight not profit.
    return dp[i][pro] = ans;
}
void solve()
{
    cin>>n>>w;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    memset(dp,-1,sizeof dp);
    int mxpro=1e5+5;
    int ans=0;
    for(int i=0;i<mxpro;i++){
        if(rec(1,i)<=w) ans=i;
    }
    cout<<ans;
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

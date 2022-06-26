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
const int N=1e5+5;
int n,k,a[N],dp[N];
int rec(int i)
{
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=1e9;
    for(int j=1; j<=k; j++)
    {
        if(i+j<=n) ans=min(ans,abs(a[i]-a[i+j])+rec(i+j));
        else break;
    }
    return dp[i]=ans;

}
void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<rec(1);
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

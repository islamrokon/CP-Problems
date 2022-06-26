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
void solve()
{
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    for(int i=0; i<n; i++)
    {
       cin>>a[i]>>b[i]>>c[i];
    }
    int dp[n+5][3];
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    for(int i=1; i<n; i++)
    {
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][2],dp[i-1][0]);
        dp[i][2]=c[i]+max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

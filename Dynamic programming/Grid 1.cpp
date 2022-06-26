#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define MOD ((ll)1e9+7)
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX ((int)1e9+5)
using namespace std;
queue<pair<int,int>> q;
int h,w;
string a[1005];
int dp[1005][1005];
bool vis[1005][1005];
void dfs(int i, int j)
{
    if(i>=h || j>=w || vis[i][j]==1 || a[i][j]=='#')
        return;
    if(i==h-1 && j==w-1)
    {
        dp[i][j]=1;
        return;
    }
    vis[i][j]=1;
    dfs(i+1,j);
    dfs(i,j+1);
    dp[i][j]=((dp[i][j]%MOD) + (dp[i][j+1]%MOD))%MOD;
    dp[i][j]=((dp[i][j]%MOD) + (dp[i+1][j]%MOD))%MOD;
}
void solve()
{

    cin>>h>>w;
    for(int i=0; i<h; i++)
    {
        cin>>a[i];
    }
    dfs(0,0);
    cout<<dp[0][0];
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

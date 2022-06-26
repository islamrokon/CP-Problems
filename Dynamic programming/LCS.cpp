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
string s,t;
int dp[3005][3005];
int rec(int i, int j)
{
    if(i==s.size() || j==t.size())
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=rec(i+1,j);
    ans=max(ans,rec(i,j+1));
    if(s[i]==t[j])
    {
        ans=rec(i+1,j+1)+1;
    }
    return dp[i][j]=ans;
}
void print(int i, int j)
{
    if(i==s.size() || j==t.size())
        return;
    if(s[i]==t[j])
    {
        cout<<s[i];
        print(i+1,j+1);
        return;
    }
    int x=rec(i+1,j);
    int y=rec(i,j+1);
    if(x>=y)
    {
        print(i+1,j);
    }
    else
        print(i,j+1);
}
void solve()
{
    cin>>s>>t;
    memset(dp,-1,sizeof dp);
    rec(0,0);
    print(0,0);
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

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
int n;
double a[3005],dp[3005][3005];
bool vis[3005][3005];
double rec(int i, int head, int tail)
{
    if(i==n+1)
    {
        if(head>tail) return 1;
        else return 0;
    }
    if(vis[i][head] == 1) return dp[i][head];
    vis[i][head]=1;
    double ans = a[i]*rec(i+1,head+1,tail);
    ans+=(1-a[i])*rec(i+1,head,tail+1);
    return dp[i][head] = ans;
}
void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    cout<< fixed << setprecision(10)<<rec(1,0,0);
}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

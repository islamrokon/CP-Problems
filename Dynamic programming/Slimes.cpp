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
const int N = 405;
const ll INF = 1e18;
ll dp[N][N];
ll sum[N][N];
void solve()
{
    int n;
    cin>>n;
    int a[n+2];
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++)
    {
        sum[i][i] = a[i];
        dp[i][i] = 0;
    }
    for(int w = 2; w <= n; w++)
    {
        for(int l = 0, r = w - 1; r < n; l++, r++)
        {
            //cout<<"l+1 "<<l+1<<" r "<<r<<endl;
            //cout<<sum[l+1][r]<<endl;
            sum[l][r] = a[l] + sum[l+1][r];
            //cout<<sum[l][r]<<endl;
            dp[l][r] = INF;
            for(int i = l; i < r; i++)
            {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r] + sum[l][r]);
                /*if(l==0 && r==3)
                cout<<dp[l][r]<<endl;*/
            }
        }
    }
    //cout<<dp[0][n-1];

}
int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}

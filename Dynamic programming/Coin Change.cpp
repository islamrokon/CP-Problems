#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 100000007
using namespace std;
int n, k, arr[55], c[55], ans = 0, dp[55][1005], cs = 1;
void solve()
{
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>c[i];
    }
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1; /// if k is 0 then dp[i][0] = 1 because if we don't take that value then 1 way exist.
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int cnt = 0; cnt <= c[i]; cnt++){
                if(j - cnt * arr[i] >= 0){
                    dp[i][j] += dp[i - 1][j - cnt * arr[i]];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout<<"Case "<<cs++<<": ";
    cout<<dp[n][k]<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

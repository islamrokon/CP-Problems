#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e9+8
using namespace std;
int dp[22][4], cs = 1;
void solve()
{
    int n;
    cin>>n;
    int arr[n+5][5];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin>>arr[i][j];
        }
    }
   memset(dp, MAX, sizeof dp);
    for(int i = 1; i <= 3; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                        if(j != k)
                    dp[i][j] = min(dp[i][j], arr[i][j] + dp[i - 1][k]);
                }

        }
    }
    int ans = MAX;
    for(int i = 1; i <= 3; i++){
        ans = min(ans, dp[n][i]);
    }
    cout<<"Case "<<cs++<<": ";
    cout<<ans<<'\n';

}
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

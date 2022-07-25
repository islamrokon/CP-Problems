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
int n, k, arr[102], dp[10005], cs = 1;
/*int rec(int i, int j)
{
    if(j == 0) return 1;
    if(j < 0) return 0;
    if(i >= n) return 0;
    if(dp[i][j] != -1) return  dp[i][j];
    return dp[i][j] = ((rec(i, j - arr[i]) % MOD) + (rec(i + 1, j) % MOD)) % MOD;
}*/
void solve()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
             if(j - arr[i] >= 0) {
                    dp[j] += dp[j - arr[i]];
                    dp[j] %= MOD;
                }
        }
    }
    cout << "Case " << cs++ << ": ";
    cout << dp[k] << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

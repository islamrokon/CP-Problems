#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000000003
using namespace std;
const int N = 1005;
int dp[N][N];
int n;
int rec(int i, int rem)
{
    if(rem < 0) return 0;
    if(i > n){
        if(rem == 0) return 1;
        return 0;
    }
    if(dp[i][rem]!= -1) return dp[i][rem];
    int ans = (rec(i + 1, rem) + rec(i + 2, rem - 1)) % MOD;
    return dp[i][rem] = ans % MOD;
}
void solve()
{
    int k;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    int ans = rec(2, k);
    memset(dp, -1, sizeof dp);
    n--;
    ans = (ans + rec(3, k - 1)) % MOD;
    cout << ans;
}
int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
}

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e18
using namespace std;
const int N = 2010;
int n, t[N];
ll c[N], dp[N][N];
ll rec(ll i, ll j)
{
    if(i > n){
        if(j == 0) return 0;
        else return MAX;
    }
    ll ans = MAX;
    if(dp[i][j] != -1) return dp[i][j];
    ans =  rec(i + 1, j);
    ans = min(ans, c[i] + rec(i + 1, max(0LL, j - t[i])));
    return dp[i][j] = ans;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        t[i]++;
    }
    memset(dp, -1, sizeof dp);
    cout << rec(1, n);
}
int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
}

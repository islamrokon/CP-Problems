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
const int N = 105;
int arr[N], dp[105][100005];
int n;
set<int>s;
int rec(int i, int sum)
{
    s.insert(sum);
    if(i >= n) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    int ans = rec(i + 1, sum + arr[i]);
    ans += rec(i + 1, sum);
    return dp[i][sum] = ans;
}
void solve()
{
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    s.clear();
    rec(0, 0);
    int ans = 0;
    for(auto a : s)
        ans += a;
    cout << ans << '\n';
}
int main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

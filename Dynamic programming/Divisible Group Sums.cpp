#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e8
using namespace std;
int n, q, d, m, cs = 0;
ll dp[205][22][25];
vector<int> vec(205),vec1(205);
ll backtracking(int i, int j, int sum)
{
    if(j == m)
    {
        if(sum % d == 0) return 1;
        else return 0;
    }
    if(i >= n || j > m) return 0;
    if(dp[i][j][sum] != -1) return dp[i][j][sum];
    ll ans = 0;
    ans += backtracking(i + 1, j, (sum+d)%d);
    ans += backtracking(i + 1, j+1, (((sum % d)+ (vec1[i] % d) + d) % d));
    return dp[i][j][sum] = ans;
}
void solve()
{
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    for(int i = 0; i < q; i++)
    {
        cin >> d >> m;
        for(int i = 0; i < n; i++) vec1[i] = vec[i] % d;
        memset(dp, -1, sizeof dp);
        if(i == 0)
            cout<<"Case "<<cs<<":\n";
        cout<<backtracking(0, 0, 0)<<'\n';
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cs++;
        solve();
    }
}

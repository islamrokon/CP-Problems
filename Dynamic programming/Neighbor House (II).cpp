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
int n, arr[1002], cs = 1;
int dp[1005][2][2];
int rec(int i, int j, bool k)
{
    if(i >= n) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = 0;
    if(i == 0){
        ans = rec(i + 1, 1, 1) + arr[i];
        ans =max(ans, rec(i + 1, 0, 0));
    }
    else if(j || (i == n-1 && k)){
        ans = rec(i + 1, 0, k);
    }
    else{
       ans = rec(i + 1, 1, k) + arr[i];
       ans = max(ans, rec(i + 1, 0, k));
    }
    return dp[i][j][k] = ans;

}
void solve()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << "Case "<< cs++ << ": ";
    cout << rec(0, 0, 0) << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}

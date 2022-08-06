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
int cs = 0;
ll solve()
{
    int n, k;
    cin >> n;
    int a = 2 * n + 5;
    int arr[a][a], dp[a][a];
    for(int i = 1; i < (int)(2 * n); i++)
    {
        if(i > n) k--;
        else k = i;
        for(int j = 1; j <= k; j++)
        {
            cin >> arr[i][j];
        }
    }
    if(n == 1)
    {
        cout << "Case " << ++cs << ": ";
        cout << arr[1][1] << '\n';
        return 0;
    }
    dp[2][1] = arr[1][1] + arr[2][1];
    dp[2][2] = arr[1][1] + arr[2][2];
    dp[3][1] = max(arr[3][1] + dp[2][1], arr[3][1] + dp[2][2]);

    if(n == 2)
    {
        cout << "Case " << ++cs << ": ";
        cout << dp[3][1] << '\n';
        return 0;
    }
    for(int i = 3; i < (int)(2 * n); i++)
    {
        if(i > n) k--;
        else k = i;
        for(int j = 1; j <= k; j++)
        {
            if(i <= n)
            {
                if(j == 1) dp[i][j] = arr[i][j] + dp[i - 1][j];
                else if(j == k) dp[i][j] = arr[i][j] + dp[i - 1][j  - 1];
                else dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j + 1] + arr[i][j]);
            }
        }
    }
    cout << "Case " << ++cs << ": ";
    cout << dp[2 * n - 1][1] << '\n';
    return 0;
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

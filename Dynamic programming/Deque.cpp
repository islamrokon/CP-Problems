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
ll dp[3005][3005][2];
int main()
{
    /// key point --> Taro will think from first after watching the array that how he will maximize his score
    /// if values are right then he will maximize because he has the first turn, he can take
    /// the first turn over thinking about full array that how he can maximize.
    ll n,sum=0;
    cin>>n;
    vector<ll> a(n);
    for(ll &x: a)
    {
        cin>>x;
        sum+=x;
    }
    for(int i=0; i<n; i++)
    {
        dp[i][i][0] = a[i]; ///if only one score remains.(if L==R)
        dp[i][i][1] = 0;
    }
    for(ll RminusL = 1; RminusL < n; RminusL++) ///it's starting from 1 means we are starting with 2 elements.
    {
        for(ll L = 0; L + RminusL < n; L++)
        {
            ll R=L + RminusL;
            ///dp[L+1][R][1] L has been taken now minimum of ***(L+1 to R) of 1 will be added because maximum will take Y
            ///similarly it is for dp[L][R-1][1].
            dp[L][R][0] = max(a[L] + dp[L+1][R][1], a[R] + dp[L][R-1][1]); ///minimum value of Y will get X, thus it will be added here
            //cout<<"L "<<L<<" R "<<R<<endl;
            //cout<<"X "<<dp[L][R][0]<<endl;
            dp[L][R][1] = min(dp[L+1][R][0], dp[L][R-1][0]); ///maximum will store for Y so minimum will remain for the X.
            //cout<<"Y "<<dp[L][R][1]<<endl;
        }
    }
    //cout<<dp[0][n-1][1]<<endl;
    ll X = dp[0][n-1][0] - dp[0][n-1][1];
    //ll ans = 2*X-sum;
    cout<<X;
}

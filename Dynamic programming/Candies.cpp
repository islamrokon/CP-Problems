///https://www.youtube.com/watch?v=dviTaAZRqCo
///https://www.youtube.com/watch?v=8eSKae2e-yA&t=621s
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
const int mod=1e9+7;
int n,k,a[102],dp[102][100005];
int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<=a[0]; i++){
        dp[0][i]=1;
    }
    for(int i=1; i<n; i++){
        vector<int>prefix_sum(k+1);
        prefix_sum[0]=dp[i-1][0];
        for(int j = 1; j<k+1; j++){
            prefix_sum[j]=(prefix_sum[j-1]+dp[i-1][j])%mod;
        }
        for(int j=0; j<k+1; j++){
            if(j>a[i]) dp[i][j] = (prefix_sum[j] + mod - prefix_sum[j-a[i]-1]) % mod;
            else dp[i][j] = prefix_sum[j];
        }
    }
    cout<<dp[n-1][k];

}

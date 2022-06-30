/// https://www.youtube.com/watch?v=apeONhTuYUU
/// https://www.youtube.com/watch?v=XRVCU2Ys9Mk
#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
double dp[305][305][305];
void solve()
{
    int n;
    cin>>n;
    int cnt[4] = {0};
    for(int i = 0; i<n; i++){
       int x;
       cin>>x;
       cnt[x]++;
    }
    dp[0][0][0] = 0;

    for(int three = 0; three <= n; three++){
        for(int two = 0; two <= n; two++){
            for(int one = 0; one <=n; one++){
                int zero = n - one - two - three;
                if(zero == n) continue;
                if(one + two + three > n) continue;
                double val = 1;
                if(three > 0) val += (1.0 * three/n) * (dp[three - 1][two + 1][one]); /// from every three it will be two once, one once and 0 once that't why multiplying that probability with all of them.
                if(two > 0) val += (1.0 * two/n) * (dp[three][two - 1][one+1]);
                if(one > 0) val += (1.0 * one/n) * (dp[three][two][one - 1]);
                dp[three][two][one] = val/(1 - 1.0 * zero / n);
            }
        }
    }
    cout<<setprecision(9)<<fixed<<dp[cnt[3]][cnt[2]][cnt[1]];
}
int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
}

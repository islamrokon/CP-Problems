///https://chowdera.com/2021/06/20210602092453217Q.html
#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
ll solve()
{
    ll n;
    cin>>n;
    ll ans = 0,i;
///here we are doing is separating the portion of divisors from 1 to root(n) we can get all the # of divisors from it's 1 to root(n)
///like for 10, 10/2 is 5 and from 6 to 10 we get maximum multiple is 1, and for 3 we 10/3 is 3 so for 4 to 5 we get 2 rest of thing is similar
    for(i=1; i*i<=n; i++)
    {
        /*a = n/i, b = n/(i+1);
        ans += a + (ab)*i; */
        ans += (n/i);
        ans += i*(n/i-n/(i+1));
        cout<<ans<<endl;
    }
    i--;
    if(n/i == i)
        ans -= i;
    return ans;
}
int main()
{
    fast;
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        ll ans=solve();
        //cout<<"Case "<<++cas<<": "<<ans<<'\n';
    }
}

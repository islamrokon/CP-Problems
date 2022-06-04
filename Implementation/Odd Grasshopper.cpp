#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
void solve()
{
    ll x,n,add;
    cin>>x>>n;
    for(ll i=n/4*4+1;i<=n;++i)
    {
        cout<<i<<endl;
        if (x&1)
        {
            x+=i;
        }
        else
        {
            x-=i;
        }
    }
    cout<<x<<'\n';
}
main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

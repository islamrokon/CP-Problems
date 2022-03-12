#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<ll> a;
ll n,m,A,B,k;
ll backtrack(ll x, ll y )
{
    if(x==y)
    {
        auto it=upper_bound(a.begin(),a.end(),x);
        auto itt=lower_bound(a.begin(),a.end(),x);
        ll z=it-itt;
        if((z==0))
        {
            ll ans= A;
            return ans;
        }
        else
        {
            ll ans=(z)*B;
            return ans;
        }
    }
    else
    {
        ll p=y-x+1;
        auto it=upper_bound(a.begin(),a.end(),y);
        auto itt=lower_bound(a.begin(),a.end(),x);
        ll z=it-itt; ///number of avengers
        if(z==0)
        {
            ll ans=A;
            return ans;
        }
        else
        {
            ll ans= min((z)*B*p,backtrack(x,(x+y)/2)+backtrack(((x+y)/2)+1,y));
            return ans;
        }
    }
}
main()
{
    fast;
    cin>>n>>k>>A>>B;
    for(int i=0; i<k; i++)
    {
        ll x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    ll x=n,y=1;
    while(x--)
    {
        y*=2;
    }
    ll ans=backtrack(1,y);
    cout<<ans;
}

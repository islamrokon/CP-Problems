#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<ll> v;
void ans(ll open,ll close, ll op )
{
    if(open==0 && close==0)
    {
        v.push_back(op);
        return ;
    }
    if(open!=0)
    {

        ll op1=op*10+4;
        ans(open-1,close,op1);
    }
    if(close!=0)
    {
        ll op1=op*10+7;
        ans(open,close-1,op1);
    }
}
void solve()
{

    ll n;
    cin>>n;
    ll x=log10(n)+1;
    if(x%2==1)
        x++;
    ll open=x/2,close=x/2;
    ans(open,close,0);
    //ans(open+1,close+1,0);
    sort(v.begin(),v.end());
    for(auto it : v)
    {
        if(n>it)
            continue;
        cout<<it<<endl;
        break;
    }
}
main()
{
    fast;
    solve();
}

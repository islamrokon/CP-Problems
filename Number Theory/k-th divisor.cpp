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
    ll n,k;
    vector<ll>v;
    cin>>n>>k;
    v.push_back(1);
    if(n!=1)
    v.push_back(n);
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    if(k>v.size())
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<v[k-1]<<"\n";
    }
}
int main()
{
    fast;
    int t=1;
    while(t--)
    {
        solve();
    }
}

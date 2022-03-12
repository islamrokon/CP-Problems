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
    ll n,k=1,p=3;
    cin>>n;
    while(k<n)
    {
        k+=p;
        p=p*3;
    }
    //cout<<p<<k<<endl;
    while(p)
    {
        if(k-p>=n)
            k=k-p;
        p=p/3;
    }
    cout<<k<<'\n';
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();

    }
}

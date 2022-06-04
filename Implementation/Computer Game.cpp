#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;

void solve()
{
    ll k,n,a,b;
    ll l,r,mid,mul,mul1,ans=0;
    cin>>k>>n>>a>>b;
    l=1;
    r=n;
    if(b*n>=k)
    {
        cout<<"-1\n";
    }
    else
    {
        while(l<=r)
        {
            mid=(l+r)/2;
            mul=mid*a;
            mul1=(n-mid)*b;
            if(mul+mul1<k)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
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

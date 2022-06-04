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
    int n,h,ans;
    cin>>n>>h;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    ans=h/(a[n-1]+a[n-2]);
    ans*=2;
    h%=(a[n-1]+a[n-2]);
    if(h>0)
    {
        h-=a[n-1];
        ans++;
        if(h>0)
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
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

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll n,q,a,b,l,r,mid,arr[100005],p=0;
int srch(int m)
{
    l=0;
    r=n;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(arr[mid]<=m)
            l=mid;
        else
            r=mid-1;
    }
   return l;
}
void solve()
{
    cin>>n>>q;
    int x,y;
    //arr[0]=-1e9;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    while(q--)
    {
        cin>>a>>b;
        y=srch(b);
        x=srch(a-1);
        cout<<y-x<<'\n';
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<++p<<":\n";
        solve();
    }
}

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
    int n,l,r,mid,ans=0,temp=0;
    cin>>n;
    ll arr[n],sum;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            sum=arr[i]+arr[j];
            l=j;
            r=n;
            while(l<=r)
            {
                mid=(l+r)/2;
                //cout<<l<<" "<<r<<" "<<mid<<endl;
                if(arr[mid]<sum)
                {
                    temp=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            ans+=temp-j;
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    fast;
    int t,p=0;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<++p<<": ";
        solve();
    }
}

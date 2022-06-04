#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int p=0;
bool solve()
{
    ll N;
    cin>>N;
    ll count=0,ans=-1;
    ll l=1,mid;
    ll r=1e18;
    while(l<=r)
    {
        count=0;
        mid=(l+r)/2;
        for(int i=5; mid/i>=1; i*=5)
        {
            count+=mid/i;
            if(count>N){
                break;
            }
        }
        if(count<N)
        {
            l=mid+1;
        }
        else if(count>N)
        {
            r=mid-1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
    }
    if(ans==-1){
        cout<<"Case "<<++p<<": impossible\n";
    }
    else
    cout<<"Case "<<++p<<": "<<l<<"\n";
}
void srch()
{

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

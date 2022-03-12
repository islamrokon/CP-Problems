#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
void phival(ll n)
{
    ll res=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            res-=res/i;
        }
    }
    if(n>1){
            res-=res/n;

    }
    cout<<res<<'\n';
}
int main()
{
    //fast;
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        phival(n);
    }
}

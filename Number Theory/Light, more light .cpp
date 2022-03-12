#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
int main()
{
    fast;
    ll n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        ll ans=1,cnt=0;
        while(n%2==0)
        {
            cnt++;
            n/=2;
        }
        ans=ans*(cnt+1);

        for(ll i=3; i*i<=n; i+=2)
        {

            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            ans=ans*(cnt+1);
            cnt=0;
        }
        if(n>1)
        {
            n/=n;
            cnt++;
        }
        ans=ans*(cnt+1);
        if(ans%2==0)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
}

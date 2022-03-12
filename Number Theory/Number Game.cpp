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
ll fun(ll n)
{
    ll tmp1=0;
    for(ll i=1; i*i<=n; i++)
    {
        ll tmp=0;
        ll val=0;
        if(n%i==0)
        {
            tmp=n/i; /// i and tmp are the divisors.
            if(tmp%2!=0 || i%2!=0)
            {
                if(tmp%2!=0 && i%2!=0)
                {
                    val=max(tmp,i);
                }
                else if(tmp%2!=0 && i%2==0)
                {
                    val=tmp;
                }
                else
                    val=i;
            }
        }
        if(val>tmp1)
        {
            tmp1=val; ///tmp1 is the greatest odd divisor of n.
        }
    }
    return tmp1;
}
void solve()
{
    ll n,tmp1=0;
    cin>>n;
    ll x=fun(n);
    tmp1=n/2;
    bool prime=1;
    for(ll i=2; i*i<=tmp1; i++)
    {
        if(tmp1%i==0)
            prime=0;
    }
    if(n==2)
        cout<<"Ashishgup\n";
    else if(n==1)
        cout<<"FastestFinger\n";
    else if(n%2!=0)
        cout<<"Ashishgup\n";
    else
    {
        if(n%2==0 && x==1)
            cout<<"FastestFinger\n";
        else if(n%4==0 && x>1)
            cout<<"Ashishgup\n";
        else if(prime)
        {
            cout<<"FastestFinger\n";
        }
        else
            cout<<"Ashishgup\n";
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

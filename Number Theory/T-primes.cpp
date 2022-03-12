#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
using namespace std;
void solve()
{
    ll n;
    int cnt=0;
    cin>>n;
    int val=sqrt(n); ///16->4 now prime factors of 4
    while(val%2==0)
    {
        cnt++;
        val/=2;
    }
    for(int i=3; i<sqrt(val); i+=2)
    {
        while(val%i==0)
        {
            cnt++;
            val/=i;
        }
    }
    cout<<cnt<<endl;
    if(cnt>1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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


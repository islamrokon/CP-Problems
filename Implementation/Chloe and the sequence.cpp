#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll n,k,mid,ans;
void fun(ll p,ll a)
{
    mid=(pow(2,p)/2);
    if(a<mid)
    {
        fun(p-1,a);
    }
    else if(a>mid)
    {
        fun(p-1,a-mid);
    }
    else
       cout<<p;
}
int main()
{
    fast;
    cin>>n>>k;
    fun(n,k);
}

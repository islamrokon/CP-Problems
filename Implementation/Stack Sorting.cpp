#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
const long N=2e5+1;
ll n,k,arr[N],t=1;
stack<ll>stk;
int main()
{
    cin>>n>>k;
    stk.push(n+1);
    for(ll i=0; i<n; i++)
    {
        if(i<k)
            cin>>arr[i];
        else
            arr[i]=stk.top()-1;
        stk.push(arr[i]);
        while(stk.size()&&stk.top()==t)
        {
            stk.pop();
            t++;
        }
    }
    if(stk.size())
    {
        cout<<"-1";
        exit(0);
    }
    for(long i=0; i<n; i++)
        cout<<arr[i]<<' ';
}

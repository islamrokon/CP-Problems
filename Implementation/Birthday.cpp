#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
multiset<ll>s;
multiset<ll>::iterator it,it1;
int main()
{
    fast;
    int n;
    cin>>n;
    ll a,arr[n],ar[n],x=0,y=0;
    while(n--)
    {
        cin>>a;
        s.insert(a);
    }
    it=s.begin();
    while(it!=s.end())
    {
        arr[x]=*it;
        it++;
        if(it==s.end())
        {
            x++;
            break;
        }
        ar[y]=*it;
        it++;
        x++;
        y++;
    }
    for(int i=0; i<x; i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i=y-1; i>=0; i--)
    {
        cout<<ar[i]<<" ";
    }
}

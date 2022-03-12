#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll a,b;
ll ans=0;
vector<ll>vec,vec1;
void backtrack(ll x)
{
    //cout<<x<<endl;
    if(x<b)
    {
        vec.push_back(x);
        backtrack(x*2);
        backtrack(x*10+1);
        vec.pop_back();
    }
    else if(x==b)
    {
        vec.push_back(x);
        vec1=vec;
        ans=1;
        return;
    }
    else
    {
        return;
    }
}
main()
{
    fast;
    cin>>a>>b;
    backtrack(a);
    if(ans>0)
    {
        cout<<"YES\n"<<vec1.size()<<'\n';
        for(auto a:vec1)
            cout<<a<<" ";
    }
    else
    {
        cout<<"NO";
    }
}

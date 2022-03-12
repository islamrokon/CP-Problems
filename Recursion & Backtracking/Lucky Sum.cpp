#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<ll>vec;
void backtrack(ll i,ll x)
{
    vec.push_back(x);
    if(i < 10)
    {
        backtrack(i + 1, x * 10 + 4);
        backtrack(i + 1, x * 10 + 7);
    }
}
main()
{
    fast;
    ll l,r,sum=0;
    cin>>l>>r;
    backtrack(1,4);
   // backtrack(1,7);
    vec.push_back(0);
    sort(vec.begin(),vec.end());
    for(int i=0; i<vec.size()-1; i++)
    {
        if(r<l)
            break;
        if(l<=vec[i])
            sum+=vec[i]*(min(vec[i],r)-l+1),l=vec[i]+1;
    }
    cout<<sum;
}

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
const ll N = 1ll << 32;
using namespace std;
main()
{
    fast;
    ll l,n,x,ans=0;
    vector<ll>vec;
    string str;
    cin>>l;
    vec.push_back(1);
    for(int i=0; i<l; i++)
    {
        cin>>str;
        if(str=="add")
        {
            ans+=vec.back();
        }
        else if(str=="for")
        {
            cin>>n;
            vec.push_back(min(N,vec.back()*n));
        }
        else if(str=="end")
        {
            vec.pop_back();
        }
    }
    if(ans>=N)
        cout<<"OVERFLOW!!!";
    else
    cout<<ans;
}

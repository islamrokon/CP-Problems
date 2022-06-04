#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
void solve()
{
    map<int,map<int,int>>mp;
    map<int,map<int,int>>:: iterator it;
    vector<int>vec;
    int n,l,r,a=1;
    cin>>n;
    vec[n]=n;
    mp[n-1].insert(make_pair(1,n));
    for(int i=1; i<n; i++)
    {
        it=mp.begin();
        l=a;
        r=n;
        if(n&1)
        {
            a=(n/2)+1;
        }
        else
        {
            a=n/2;
        }
        vec[a]=i;
        mp[a-l-1].insert(make_pair(l,a-1));

        mp[n-a-1].insert(make_pair(a+1,r));

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

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
void solve()
{
    map<char,int>mp;
    string str,s;
    cin>>str>>s;
    ll ans=0;
    for(int i=0;i<str.size();i++){
        mp[str[i]]=i+1;
    }
    for(int i=0;i<s.size()-1;i++){
        ans+=abs(mp[s[i]]-mp[s[i+1]]);
    }
  cout<<ans<<'\n';
}
main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

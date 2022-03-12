#include<bits/stdc++.h>
#define ll unsigned long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define base 31
#define x first
#define y second
using namespace std;
ll h[M],h1[M];
map<ll,ll>mp;
int cnt[M];
void hashvalue(string &s)
{
    h[0]=1;
    for(int i=1; i<s.size(); i++)
    {
        h[i]=h[i-1]*base+h[i]+1;
        mp[h[i]]++;
    }
    h1[0]=1;
    for(int i=2; i<s.size(); i++)
    {
        h1[i]=h[i-1]*base+h1[i]+1;
        mp[h1[i]]++;
    }
}
void solve()
{
    string str;
    cin>>str;
    hashvalue(str);
    for(int i=0;i<str.size();i++){
        cout<<h1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<str.size();i++){
        cout<<h[i]<<" ";
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

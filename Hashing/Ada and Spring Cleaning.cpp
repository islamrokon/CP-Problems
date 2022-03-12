#include<bits/stdc++.h>
#define ll unsigned long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10000008
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 257
using namespace std;
ll p[M];
void solve()
{
    ll h[100007];
    unordered_map<ll,ll>ump;
    int n,k,cnt=0;
    cin>>n>>k;
    string str;
    cin>>str;
    h[0]=str[0]-'a'+1;
    if(k==1)
        ump[h[0]]++, cnt++;
    for(int i=1; i<str.size(); i++)
    {
        h[i]=(h[i-1]*base)+str[i]-'a'+1;
   //cout<<h[i]<<" ";
        if(i==k-1)
        {
            ump[h[i]]++;
            cnt++;
        }
        else if(i>=k)
        {
            ll hval=h[i]-(h[i-k]*p[k]);
           // cout<<hval<<" ";
            if(ump.find(hval)==ump.end())
            {
                ump[hval]++;
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
}
int main()
{
    fast;
    p[0]=1;
    for(int i=1; i<M; i++)
    {
        p[i]=p[i-1]*base;
    }
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

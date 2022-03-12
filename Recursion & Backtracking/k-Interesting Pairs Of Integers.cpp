#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int n, k,x;
int cnt[10500];
int bi[20500];
main()
{
    fast;
    cin>>n>>k;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        cnt[x]++;
    }
    int lim=10050;
    for(int i = 0; i < 2 * lim; i++)
    {
        bi[i]=__builtin_popcount(i);
    }
    if(k==0)
    {
        for(int i=0; i<lim; i++)
        {
            ans+=(cnt[i]-1)*1ll*cnt[i]/2;
        }
    }
    else
    {
        for(int i=0; i<lim; i++)
        {
            for(int j = i + 1; j < lim; j++)
            {
                if(bi[i^j]==k)
                {
                    ans+=cnt[i]*1ll*cnt[j];
                }
            }
        }
    }
    cout<<ans;
}

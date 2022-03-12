#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
using namespace std;
vector<uint>pprime,prime; ///prime prefix
bool iscomp[M];
void preprocess()
{
    for(ll i=2; i<M; i++)
    {
        if(!iscomp[i])
        {
            for(ll j=i*i; j<M; j+=i)
            {
                iscomp[j]=1;
            }
        }
    }
    ll tmp=1;
    for(ll i=2; i<M; i++)
    {
        if(!iscomp[i])
        {
            prime.push_back(i);
            tmp*=i;
            pprime.push_back(tmp);
        }
    }
}
void solve()
{
    uint ans=1;
    int n;
    ll psz=(int)prime.size();
    cin>>n;
    int idx = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
    idx--;
    //cout<<prime[idx]<<endl;
    //cout<<idx<<endl;
    ans*=pprime[idx];
    //cout<<ans<<endl;
   for (int i = 0; i < psz; i++)
    {
        ll p = prime[i];
        ll x = n;
        x--;
        ll a = 0;
        if (p * p > n)
            break;
        while (x >= p)
        {
            x /= p;
            a++;
        }
        ans *=pow(p, a - 1);
    }
    cout<<ans<<endl;
}
int main()
{
    fast;
    preprocess();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

}

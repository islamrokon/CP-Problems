#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
bool iscomp[50];
vector<ll>vec[1400],primes;
void seive()
{
    for(int i=2; i*i<=1000037; i++)
    {
        if(!iscomp[i])
        {
            for(int j=i*i; j<=1000037; j+=i)
            {
                iscomp[j]=1;
            }
        }
    }
    for(int i=2; i<=1000037; i++)
    {
        if(!iscomp[i])
            primes.push_back(i);
    }
}
void preprocess()
{
    ///calculating number divisors by prime factorization
    ///number of divisors
    vec[1].push_back(1);
    for(ll i=2; i<=100010; i++)
    {
        ll res=1;
        ll tmp=i*i; ///calculating divisors of square values because of odd # of divisors
        //cout<<i<<" "<<tmp<<endl;
        ll val=tmp;
        for (auto d : primes)
        {
            int cnt=0;
            // cout<<"ok"<<d<<endl;;
            if (d * d > tmp) /// if d can't come twice because d*d cross just one next prime number that tmp is so small that it could be prime itself
            {
                //cout<<"ok\n";
                break;
            }
            while (tmp % d == 0)
            {
                //cout<<tmp<<endl;
                tmp /= d;
                cnt++;  ///power of a prime number
            }
            //cout<<d<<" "<<cnt<<endl;
            res*=2*(cnt+1);
        }
        // cout<<"jhamela0    "<<res<<endl;
        if (tmp > 1)
        {
            //cout<<"done";
            res*=3;
        }
        vec[res].push_back(val);
        //cout<<"jhamela";
    }
}
void solve()
{
    ll k,low,high;
    cin>>k>>low>>high;
    sort(vec[k].begin(),vec[k].end());
    auto l=lower_bound(vec[k].begin(),vec[k].end(),low)-vec[k].begin();
    auto h=upper_bound(vec[k].begin(),vec[k].end(),high)-vec[k].begin();
    int ans=h-l;
    cout<<ans<<'\n';
}
int main()
{
    fast;
    seive();
    preprocess();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

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
int main()
{
    fast;
    string s,r;
    ll pH1[M + 5], po1[M + 5],pH2[M + 5], po2[M + 5];
    cin>>s;
    ll  n=s.size();
    ll dp[n+10]= {0};
    ll j=s.size()-1;
    ll hh1=s[0],hh2=s[0],po=1;
    dp[1]=1; ///we are not comparing the hash value of length 1 because answer will be must greater equal 1.
    for(ll i=1; i<n; i++)
    {
        //cout<<s[i]<<endl;
        hh1=(hh1*base+s[i])%MOD; ///if the string is abc this line calculating hash value of abc
        //cout<<hh1<<endl;
        hh2=((s[i])*base*po+hh2)%MOD; ///and this line calculating the hash value of opposite of abc which is cba
        //cout<<hh2<<endl;
        po*=base;
        po%=MOD;
        if(hh1==hh2)
            dp[i+1]=dp[(i+1)/2]+1;
            //cout<<dp[i+1]<<endl;
    }
    ll ans=0;
    for(int i=0; i<n+1; i++)
    {
        ans+=dp[i];
    }
    cout<<ans<<'\n';

    return 0;
}

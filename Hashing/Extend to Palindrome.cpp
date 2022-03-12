#include<bits/stdc++.h>
#define ll unsigned long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 53
using namespace std;
ll h[M],p[M];
ll hashval(string &s)
{
    h[0]=s[0]-'a'+1;
    for(int i=1; i<s.size(); i++)
    {
        h[i]=h[i-1]*base+s[i]-'a'+1;
    }
    ll hval=h[s.size()-1];
    ll temp=hval;
    ll temp1=hval;
    int cnt=s.size()-1;
    bool ok=0;
    for(int i=0; i<=s.size(); i++)
    {
        ll rvseno=0;
        if(ok)
        {
            temp1=hval-h[i-1]*p[cnt--];
            temp=temp1;
        }
        ok=1;
        while(temp)
        {
            int rmndr=temp%base;
            rvseno=rvseno*base+rmndr;
            temp/=base;
        }
        if(rvseno==temp1)
        {
            return temp1;
        }
    }
}

int main()
{
    p[0]=1;
    for(int i=1; i<M; i++)
        p[i]=p[i-1]*base;
    string str;
    while(cin>>str)
    {
        string ps=str;
        reverse(ps.begin(),ps.end());
        if(ps==str)
            cout<<str<<'\n';
        else
        {
            ll ans= hashval(str);
            string ss;
            while(ans)
            {
                int tmp=ans%base;
                ss+=tmp%base+97-1;
                ans/=base;
            }
            //reverse(ss.begin(),ss.end());
            int sz=ss.size();
            string tstr=str;
            while(sz)
            {
                str.pop_back();
                sz--;
            }
            reverse(str.begin(),str.end());
            cout<<tstr+str<<'\n';
        }
    }
}

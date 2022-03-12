#include<bits/stdc++.h>
#define ll unsigned long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 257
using namespace std;
char st[30];
string str[30000],s[30000],tstt;
ll h[M];
set<string>stt;
int cnt=0;
unordered_map<ll,set<int>>ump;
void hashvalue(string &ts)
{
    h[0]=ts[0]-'a'+1;
    ump[h[0]].insert(cnt);
    for(int i=1; i<ts.size(); i++)
    {
        h[i]=h[i-1]*base+ts[i]-'a'+1;
        ump[h[i]].insert(cnt);
    }
    cnt++;
}
ll hashval(string &ss)
{
    ll hval=ss[0]-'a'+1;
    for(int i=1; i<ss.size(); i++)
        hval=hval*base+ss[i]-'a'+1;
    return hval;
}
int main()
{
    fast;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>st;
        str[i]=st;
        hashvalue(str[i]);
    }
    int k,cas=1;
    cin>>k;
    for(int i=0; i<k; i++)
    {
        cin>>tstt;
        ll temp=hashval(tstt);
        if(ump.find(temp)!=ump.end())
        {
            cout<<"Case #"<<cas++<<":\n";
            for(auto a:ump[temp])
                stt.insert(str[a]);
            for(auto b:stt)
                if(b!=tstt)
                    cout<<b<<'\n';
            stt.clear();
        }
        else
        {
            cout<<"Case #"<<cas++<<":\n";
            cout<<"No match.\n";
        }

    }
}

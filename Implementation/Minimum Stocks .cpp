#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
map<ll,string>mp;
map<ll,string>:: iterator it;
ll p,typ,d;
string str;
void solve()
{
    d++;
    cin>>typ;
    if(typ==1)
    {
        cin>>str;
        cin>>p;
        mp[p]=str;

    }
    else if(typ==2)
    {
        cin>>str;
        cin>>p;
        mp[p]=str;

    }
    else
    {
        cin>>str;
        it=mp.begin();
        cout<<it->second<<" "<<d<<"\n";
        mp.erase(it);

    }

}
int main()
{
    fast;
    int n;
    cin>>n;
    while(n--)
    {
        solve();
    }
}

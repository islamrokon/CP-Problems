#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
void solve()
{
    ll q,a,b;
    set<ll>s,s1;
    set<ll>:: iterator it,it1,it2,it3,it4,it5;
    map<ll,ll>mp,mp1;
    map<ll,ll>:: iterator mt,mt1;
    ll n,m,x,y;
    s.insert(0);
    s1.insert(0);
    cin>>n>>m>>q;
    a=n;
    b=m;
    s.insert(n);
    s1.insert(m);
    for(int i=0; i<q; i++)
    {
        cin>>x;
        if(x==0)
        {
            cin>>y;
            s.insert(y);
            it=s.find(y);
            it1=it;
            it1--;
            it2=it;
            it2++;
            mp[*it-*it1]++;
            mp[*it2-*it]++;
            mp[*it2-*it1]--;
            if(mp[*it2-*it1]<=0)
            {
                mp.erase(*it2-*it1);
            }
            mt=mp.end();
            mt--;
            a=mt->first;
        }
        else if(x==1)
        {
            cin>>y;
            s1.insert(y);
            it3=s1.find(y);
            it4=it3;
            it4--;
            it5=it3;
            it5++;
            mp1[*it3-*it4]+=1;
            mp1[*it5-*it3]+=1;
            mp1[*it5-*it4]-=1;
            if(mp1[*it5-*it4]<=0)
            {
                mp1.erase(*it5-*it4);
            }
            mt1=mp1.end();
            mt1--;
            b=mt1->first;

        }
        cout<<a*b<<"\n";
        if(i==q-1)
        {
            s.clear();
            s1.clear();
            mp.clear();
            mp1.clear();
        }
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

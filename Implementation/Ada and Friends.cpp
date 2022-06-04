#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int main()
{
    set<pair<ll,string>>s;
    set<pair<ll,string>>:: iterator it;
    map<string,ll>mp;
    map<string,ll>:: iterator mt;
    ll q,k,e,p=0;
    string str;
    cin>>q>>k;
    for(int i=0;i<q;i++){
        cin>>str;
        cin>>e;
        mp[str]+=e;


    }
    for(mt=mp.begin(); mt!=mp.end(); mt++)
    {
        s.insert(make_pair(mt->second,mt->first));
    }

     /*for(it=s.begin(); it!=s.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }*/

    it=s.end();
    it--;
    if(k>s.size()){
        k=s.size();
    }
    for(int i=0; i<k; i++)
    {
        p=p+it->first;
        it--;
    }
    cout<<p;
}

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
    ll n,a=0,ans=0;
    priority_queue<ll>s;
    cin>>n;
    ll arr[n],sum[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    if(s.size()==1)
    {
        it=s.begin();
        cout<<*it<<"\n";
    }
    else
    {
        while(s.size()>1)
        {
            it=s.end();
            it--;
            it1=it;
            it1++;
            sum[a]=(*it)+(*it1);
            s.erase(it);
            s.erase(it1);
            s.insert(sum[a]);
            a++;
        }
        for(int i=0; i<a; i++)
        {
            ans=sum[i]+ans;
        }
        cout<<ans<<"\n";
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


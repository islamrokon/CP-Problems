///https://www.youtube.com/watch?v=3TayhiZb0gI&t=498s
///40 min
#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
vector<pair<ll,ll>>grp[M];
ll dis[M];
ll vis[M]={0};
ll mx,mxnode,k=1;
void dfs(ll s,ll d)
{
    vis[s] = 1 ;
    cout<<dis[s]<<" "<<d<<endl;
    dis[s] = max(d, dis[s]) ;
    if(d>mx)
    {
        mx = d ;
        mxnode = s ;
    }

    ll i;
    for(i=0; i<grp[s].size(); i++)
    {
        if(vis[grp[s][i].first] == 0)
        {
            dfs(grp[s][i].first, d+grp[s][i].second);
        }
    }
}
void solve()
{
    int n,u,v,w;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v>>w;
        grp[u].push_back({v,w});
        grp[v].push_back({u,w});
    }
    mx=0;
    ll p,q;
    ll pdif[n+1],qdif[n+1];
    dfs(0,0);
    p=mxnode;
    memset(vis,0,sizeof vis);
    mx=0;
    dfs(p,0);
    q=mxnode;
    for(int i=0; i<n; i++)
    {
        pdif[i]=dis[i];
    }
    dfs(q,0);
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    dfs(q,0);
    for(int i=0; i<n; i++)
    {
        qdif[i]=dis[i];
    }
    /*cout<<"Case "<<k++<<":"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<max(pdif[i],qdif[i])<<endl;
    }*/
    memset(grp,0,sizeof grp);
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
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

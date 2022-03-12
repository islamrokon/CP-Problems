#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<vector<int>>grp;
vector<int>dis;
void init(int n)
{
    grp.clear();
    dis.clear();
    grp.resize(n+5);
    dis.resize(n+5,0);
}
void bfs(int strtnd)
{
    queue<int>q;
    q.push(strtnd);
    dis[strtnd]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto a:grp[x])
        {
            if(dis[a]==0)
            {
                dis[a]=dis[x]+1;
                q.push(a);
            }
        }
    }
}
void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    init(n);
    for(int j=0; j<m; j++)
    {
        cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    bfs(1);
    vector<int>even,odd;
    for(int i=1; i<=n; i++)
    {
        if(dis[i]&1)
        {
            odd.push_back(i);
        }
        else
            even.push_back(i);
    }
    if(odd.size()>even.size())
    {
        cout<<even.size()<<'\n';
        for(auto a:even)
            cout<<a<<" ";
        cout<<'\n';
    }
    else
    {
        cout<<odd.size()<<'\n';
        for(auto a:odd)
            cout<<a<<" ";
        cout<<'\n';
    }
}
int main()
{
    ///fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

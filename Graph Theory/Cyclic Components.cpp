#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<vector<int>>grp(M);
vector<int>vis(M);
set<int>s;
int cnt=0;
void init(int n)
{
    grp.clear();
    vis.clear();
    grp.resize(n+1);
    vis.resize(n+1,0);
}
void dfs(int n)
{
    s.insert(n);
    vis[n]=1;
    for(auto a:grp[n])
    {
        if(vis[a]==0)
        {
            dfs(a);
        }
    }
}
void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    init(n);
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            s.clear();
            dfs(i);
            bool flag=1;
            for(auto a:s)
            {
                if(grp[a].size()!=2)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
    }

    cout<<cnt;
}
int main()
{
    fast;
    int t=1;
    while(t--)
    {
        solve();
    }
}

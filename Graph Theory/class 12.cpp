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
vector<int>grp[M+5];
vector<int>subtreesum;
vector<bool>vis;
void init(int n)
{
    subtreesum.clear();
    vis.clear();
    subtreesum.resize(n+1);
    vis.resize(n+1,0);
}
void dfs(int u)
{
    vis[u]=1;
    for(auto v:grp[u])
    {
        if(!vis[v])
        {
            dfs(v);
            subtreesum[u]+=subtreesum[v];
        }
    }
}
int main()
{
    int n,u,v;
    cin>>n;
    init(n);
    for(int i=1; i<=n; i++)
        cin>>subtreesum[i];
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    dfs(1);
    for(int i=1; i<=n; i++)
        cout<<i<<": "<<subtreesum[i]<<endl;
}

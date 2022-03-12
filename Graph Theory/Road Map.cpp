#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<vector<int>>grp(M);
vector<int>parent(M);
vector<int>vis(M);
void dfs(int n)
{
    vis[n]=1;
    for(auto a:grp[n])
    {
        if(vis[a]!=1)
        {
            parent[a]=n;
            dfs(a);
        }
    }
}
void solve()
{
    int n,r1,r2,val;
    cin>>n>>r1>>r2;
    parent.resize(n+1);
    vis.resize(n+1);
    grp.resize(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>val;
        if(i==r1)
        {
            grp[i+1].push_back(val);
            grp[val].push_back(i+1);
            i++;
        }
        else
        {
            grp[i].push_back(val);
            grp[val].push_back(i);
        }
    }
    dfs(r2);
    for(int i=1;i<=n;i++){
            if(i!=r2)
        cout<<parent[i]<<" ";
    }

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

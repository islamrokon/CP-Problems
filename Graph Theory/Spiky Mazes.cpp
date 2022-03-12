#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<char>grp[50];
vector<int>vis[50];
int n,m,j,cnt=0;
bool found=false;
bool check(int r,int c)
{
    if(r>=0 && r<n && c>=0 && c<m)
        return true;
    else
        return false;
}
void dfs(int u,int v)
{
    int a[]= {0,-1,1,0};
    int b[]= {1,0,0,-1};
    for(int i=0; i<4; i++)
    {
        int r=u+a[i];
        int c=v+b[i];
        if(vis[r][c]!=1)
        {
            if((grp[r][c]=='.') && check(r,c))
            {
                vis[r][c]=1;
                ///sum[c][r]=sum[u][v]+1 if we want the distance of cell(c,r) from source it will be plus one with his parent distance.
                dfs(r,c);
            }
            else if(grp[r][c]=='s' && check(r,c))
            {
                vis[r][c]=1;
                cnt++;
                dfs(r,c);
            }
            else if(grp[r][c]=='x')
            {
                found=true;
                return;
            }
        }
        vis[i][j]=0;
    }
}
void solve()
{
    char val;
    cin>>n>>m>>j;
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<m; k++)
        {
            cin>>val;
            grp[i].push_back(val);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<m; k++)
        {
            if(grp[i][k]=='@')
            {
                vis[i][k]=1;
                dfs(i,k);
            }
        }

    }
    bool ok=false;

    if(found && cnt*2<=j)
        cout<<"possible";
    else
        cout<<"impossible";
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

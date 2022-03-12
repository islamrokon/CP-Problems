#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<int>grp[M];
vector<int>vis(105);
void bfs(int n)
{
    queue<int>q
}
void solve()
{
    int n,m,val;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>val;
            grp[i].push_back(val);
        }
    }
    bfs(1,1);
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

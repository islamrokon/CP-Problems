#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll dx[4]= {1,0,0,-1},dy[4]= {0,-1,1,0};
string s[1001],add="DLRU";
ll d[1001][1001],xx,yy,n,m,k;

bool valid(ll x,ll y)
{
    return (x<n && x>=0 && y<m && y>=0 && s[x][y]!='*');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=0; i<n; i++)
    {
        cin>>s[i];
        for(ll j=0; j<m; j++)
        {
            if(s[i][j]=='X')
                xx=i,yy=j;
            d[i][j]=1e9;
        }
    }
    if(k%2)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    queue<pair<ll,ll>> q;
    q.push({xx,yy});
    d[xx][yy]=0;
    while(!q.empty())
    {
        ll f=q.front().first,s=q.front().second;
        q.pop();
        for(ll i=0; i<4; i++)
        {
            ll x=f+dx[i],y=s+dy[i];
            if(valid(x,y) && d[x][y]>d[f][s]+1)
                q.push({x,y}),d[x][y]=d[f][s]+1;
        }
    }
    string ans;
    for(ll i=0; i<k; i++)
    {
        ll dir=0;
        ll x,y;
        while(dir<4)
        {
            x=xx+dx[dir],y=yy+dy[dir];
            if(valid(x,y) && d[x][y]<=k-i-1)
                break;
            dir++;
        }
        if(dir==4)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        xx=x;
        yy=y;
        ans+=add[dir];
    }
    cout<<ans;
    return 0;
}

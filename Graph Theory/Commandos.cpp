#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int grp[105][105];
int num;
int bfs(int n,int *s)
{
    queue<int> que;
    int now,next;
    memset(s,0,sizeof(s));
    now=n;
    que.push(now);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<num;i++)
        {
            next=i;
            if(grp[now][i]==1&&s[i]==0&&i!=n)
            {
                s[i]=s[now]+1;
                que.push(next);
            }
        }
    }
}
int main()
{
   //freopen("in.in.c","r",stdin);
    int T;
    int A[105],B[105];
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
        int q;
        int a,b;
        int S,E;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(grp,0,sizeof(grp));
        scanf("%d%d",&num,&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            grp[a][b]=grp[b][a]=1;
        }
        scanf("%d%d",&S,&E);
        bfs(S,A); ///distance of all nodes from s.
        bfs(E,B); ///distance of all nodes from d.
        int ans=0;
        for(int i=0;i<num;i++)
        {
            ans=max(A[i]+B[i],ans); ///longest distance for both s and d, because graph has to revisit some nodes twice, we have to visit all of the nodes then we can go to the destination node.
        }
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;
}

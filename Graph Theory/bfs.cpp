#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
vector<int>vec[M];
vector<int>clr(100);
vector<int>dis(100),parent(100); ///distance always calculated for a node from starting node.
int n;
void bfs(int startingNode)
{
    for(int i=0; i<n; i++)
    {
        clr[i]=WHITE; ///initializing all nodes unvisited.
        parent[i]=-1; ///initializing all parents node -1.
        dis[i]=INT_MIN; ///INT_MIN is -2147483648
    }
    queue<int>q;
    q.push(startingNode); ///1st of all pushing starting node in queue
    parent[startingNode]=-1; ///always parent node of starting node is -1.
    dis[startingNode]=0;    ///always distance of starting node is 0.
    while(!q.empty())
    {
        int x=q.front();
        cout<<x<<" "; ///nodes always traverse level by level like 0,1,2,3,... in bfs.
        q.pop();
        clr[x]=GRAY;
        for(auto a:vec[x]) ///traversing all adjacent node of x.
        {
            if(clr[a]==WHITE)
            {
                parent[a]=x;
                dis[a]=dis[x]+1; ///always distance of a node is +1 with parent node for unweighted graph.
                q.push(a); ///adjacent node is pushed in queue for further traversing.
            }
        }
        clr[x]=BLACK;
    }
}
int main()
{
    int u,v,edge;
    cin>>n>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v; ///edge between u and v nodes.
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    bfs(0);
    cout<<endl;
    cout<<parent[5]<<endl;
    cout<<dis[6]<<endl;
}

/*
sample input
8 7
0 1
0 2
1 3
2 4
2 5
3 6
3 7
*/

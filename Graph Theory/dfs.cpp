///https://youtu.be/-1HUUMnCRjs
#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define WHITE 0 ///not visited
#define GREY 1  ///visited but not explored
#define BLACK 2 ///explored
using namespace std;
vector<int>vec[M];
vector<int>clr(100);
int n;
void dfsVisit(int u)
{
    clr[u]=GREY; ///marked u node visited
    for(auto a:vec[u])  ///traversing all child nodes of u
    {
        if(a==WHITE)
        {
            dfsVisit(a); ///it will go to the depth to the last child node.
        }
    }
    clr[u]=BLACK; ///after traversing all child of u, marked explored.
}
void dfs()
{
    for(int i=0; i<n; i++) ///initializing all nodes unvisited
        clr[i]=WHITE;
    for(int i=0; i<n; i++)
    {
        if(clr[i]==WHITE) ///traversing all nodes if unvisited.
        {
            dfsVisit(i);
        }
    }
}
int main()
{
    int u,v,edge;
    cin>>n>>edge; ///number of nodes and number of edges.
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v; ///edge between u and v.
        vec[u].push_back(v); ///storing like, all child nodes of u are 0,1,5,4,...
        vec[v].push_back(u); ///storing like, all child nodes of v are 2,3,6,7,...
    }
    dfs();
}

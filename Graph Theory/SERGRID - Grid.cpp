#include "bits/stdc++.h"
using namespace std;

const int maxn = 505;
int n,m;
#define inRange(i,j) (i >= 1 and i <=n and j >= 1 and j <= m)

int mat[maxn][maxn],visited[maxn][maxn],level[maxn][maxn];

queue< pair<int,int> >Q;

void solve(int i,int j)
{
    Q.push(make_pair(i,j)); ///pushing index number.

    while(!Q.empty())
    {

        int node1 = Q.front().first; ///index(row)
        int node2 = Q.front().second; ///index(column)

        Q.pop();

        /// positions it can go to.
        ///like for (2,2)->(1,2);(2,1);(2,3);(3,2).
        int a[] = {0,-mat[node1][node2],0,mat[node1][node2]}; ///row, minus for subtract
        int b[] = {-mat[node1][node2],0,mat[node1][node2],0}; ///column
        ///index can be i or j - mat[node1][node2].

        for(int x = 0; x < 4; x++)
        {
            int temp1 = node1 + a[x];
            int temp2 = node2 + b[x];

            if(inRange(temp1,temp2) && !visited[temp1][temp2])
            {
                visited[temp1][temp2] = 1;
                level[temp1][temp2]  = level[node1][node2] + 1; ///from which node it's visited.
                Q.push(make_pair(temp1,temp2));
            }
        }
    }
}

int main()
{
    visited[1][1] = 1;
    cin>>n>>m;
    string S;

    for(int x = 1; x <= n; x++)
    {

        cin>>S;
        for(int j=1; j<=m; j++)
        {
            mat[x][j]=S[j-1]-'0';
        }
    }
    solve(1,1);

    if(visited[n][m] != 0)
        cout<<level[n][m]<<endl;
    else
        cout<<-1<<endl;

}
/*
4 5
2120
1203
3113
1120
1110
*/


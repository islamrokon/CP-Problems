#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e8
using namespace std;
string st1, st2, st3;
int a, b, c, dp[51][51][51], cs = 1;
void solve()
{
    cin>>st1>>st2>>st3;
    a = st1.size();
    b = st2.size();
    c = st3.size();
    //lcs(0, 0, 0);
    for(int i = 0; i <= a; i++)
    {
        for(int j = 0; j <= b; j++)
        {
            for(int k = 0; k <= c; k++)
            {
                if(i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if(st1[i - 1] == st2[j - 1] && st2[j - 1] == st3[k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    cout<<"Case "<<cs++<<": ";
    cout<<dp[a][b][c]<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

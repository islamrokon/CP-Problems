#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e9+8
using namespace std;
int a, b, cs = 1;
string dp[102][102], str, str1;
bool vis[102][102];
string lcs(int i, int j)
{
    if(i >= a || j >= b) return "";
    if(vis[i][j]) return dp[i][j];
    if(str[i] == str1[j])
    {
        return dp[i][j] = str[i] + lcs(i + 1, j + 1);
    }
    string lcs1 = lcs(i+1, j);
    string lcs2 = lcs(i, j+1);
    if(lcs1.size() > lcs2.size()) dp[i][j] = lcs1;
    else if(lcs2.size() > lcs1.size()) dp[i][j] = lcs2;
    else
    {
        if(lcs1 < lcs2) dp[i][j] = lcs1;
        else dp[i][j] = lcs2;
    }
    vis[i][j] = 1;
    return dp[i][j];
}
void solve()
{
    cin>>str>>str1;
    a = str.size();
    b = str1.size();
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            dp[i][j] = "";
        }
    }
    string ans = lcs(0,0);
    cout << "Case " << cs++ << ": ";
        if(ans.size() == 0) {
            cout << ":(" << '\n';
        }
        else cout << ans << '\n';
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

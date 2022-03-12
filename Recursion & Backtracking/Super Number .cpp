#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
bool ok;
int m,n;
int num[35];
int judge(int cur)
{
    int sum = 0;
    for(int i=1; i<=cur; i++)
    {
        sum=(sum*10+num[i])%cur;
    }
    return sum;
}
void backtrack(int cur)
{
    if(cur==m+1)
    {
        ok=true;
        return;
    }
    for(int i=0; i<10; i++)
    {
        num[cur] = i;
        if(cur<n||(cur>=n&&!judge(cur)))
        {
            backtrack(cur+1);
        }
        if(ok)
        {
            return ;
        }
    }
}
int main()
{
    fast;
    int t;
    int cas = 1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i = 1; i < 10; i++)
        {
            num[1] = i;
            ok = false;
            backtrack(2);
            if(ok)
            {
                break;
            }
        }
        cout<<"Case "<<cas++<<": ";
        if(ok)
        {
            for(int i = 1; i <= m; i++)
            {
                cout<<num[i];
            }
            cout<<'\n';
        }
        else
        {
            cout<<"-1\n";
        }
    }
}

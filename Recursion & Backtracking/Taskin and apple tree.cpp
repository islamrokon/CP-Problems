#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll arr[25],n,m;
ll temp=0;
void backtrack(ll i,ll s)
{
    if(i==n)
    {
        if(s>temp && s<=m){
            temp=s;
        }
        return;
    }
    backtrack(i+1,s);
    backtrack(i+1,s+arr[i]);
}
void solve()
{
    cin>>m>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    backtrack(0,0);
    cout<<temp<<'\n';
    temp=0;
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

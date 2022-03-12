#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define MAX ((int)1e9+5)
using namespace std;
int solve(int idx,int cap)
{
    if(cap<0) return -MAX;
    if(idx>n) return 0;
    if(dpp[idx][cap]!=-1) return dpp[idx][cap];
    int ans=-MAX;
    ans=solve(idx+1,cap-wgh[cap])+val[idx];
    ans=max(ans,solve(idx+1,cap));
    return dpp[idx][cap]=ans;
}
int main()
{
    memset(dpp,-1,sizeof dpp);
}

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD 10000007
#define x first
#define y second
using namespace std;
int t,a, b, c, d, e, f, n,cs=1;
int dp[M];
int fn(int n){

    if(n==0) return a%MOD;
    if(n==1) return b%MOD;
    if(n==2) return c%MOD;
    if(n==3) return d%MOD;
    if(n==4) return e%MOD;
    if(n==5) return f%MOD;
    int &ret=dp[n]; // save referance of dp[n] into &ret
    if(ret!=-1) return ret;
    ret=fn(n-1)%MOD+fn(n-2)%MOD+fn(n-3)%MOD+fn(n-4)%MOD+fn(n-5)%MOD+fn(n-6)%MOD;
    return ret;
}
int main(){
    fast;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>e>>f>>n;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",cs++,(fn(n)+MOD)%MOD);

    }
}

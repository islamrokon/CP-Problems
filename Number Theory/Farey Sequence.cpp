#include<iostream>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000008
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
ll phi[M];
void phival()
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2; i<M; i++)
        phi[i]=i;
    for(int i=2; i<M; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<M; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
void solve(int n)
{
    int ans=0,i=2;
    n--;
    while(n--)
    {
        //cout<<phi[i]<<endl;
        ans+=phi[i];
        i++;
    }
    cout<<ans<<'\n';
}
int main()
{
    fast;
    phival();
    int t;
    while(cin>>t)
    {
        if(t==0)
            return 0;
        solve(t);
    }
}

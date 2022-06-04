#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define Dpos(n) fixed << setprecision(n)
#define x first
#define y second
using namespace std;
double x,y,c,l,r,mid;
int i=0;
double fun(double m)
{
    double a=sqrt(x*x-m*m);
    double b=sqrt(y*y-m*m);
    return (a*b)/(a+b);
}
void solve()
{
    cin>>x>>y>>c;
    l=0;
    r=min(x,y);
    int cnt=100;
    while(cnt--)
    {
        mid=(l+r)/2;
        if(c>=fun(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<Dpos(10)<<l<<'\n';
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<++i<<": ";
        solve();
    }
}

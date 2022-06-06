#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll GCD(ll a,ll b)
{
    cout<<"B:"<<b<<endl;
    if(a % b == 0)
        return b;
    return GCD(b,a % b);
}
int main()
{
    ll a,b,x,y,temp,temp1;
    cin >> a >> b >> x >> y;
    temp = GCD(x,y);
    cout<<"temp:"<<temp<<endl;
    x =x/temp,y = y/temp;
    temp1 = min(a/x,b/y);
    cout<<"Temp1:"<<temp1<<endl;
    cout << temp1 * x << " " << temp1 * y << "\n";
    return 0;
}

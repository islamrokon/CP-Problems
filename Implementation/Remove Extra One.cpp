#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n,ans,m1,m2,x,a[100010];
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        if (x>m1)
        {
            a[x] = 1;
            m2 = m1;
            m1 = x;
        }
        else if (x>m2)
        {
            a[m1]--;
            m2 = x;
        }
    }
    ans = 1;
    for (int i=1; i<=n; i++)
    {
        if (a[i] < a[ans])
            ans = i;
    }
    cout<<ans;

}

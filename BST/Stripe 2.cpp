#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
long long n,a[100002],cnt,ans;
int main()
{
    cin>>n;  ///1 2 3 4 5
    for(int i=1; i<=n; i++)
        cin>>a[i],a[i]+=a[i-1];
   // a[n]=a[n]/3;
    for(int i=1; i<n; i++)
    {
        if(a[i]*3==a[n]*2)
            ans+=cnt;
        if(a[i]*3==a[n])
            cnt++;
    }
    cout<<ans;
    return 0;
}

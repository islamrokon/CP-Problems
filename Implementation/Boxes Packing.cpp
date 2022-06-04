#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//accept koros na kn bhai!
using namespace std;
int n,a,ans;
map<int,int> m;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a,m[a]++,ans=max(ans,m[a]);
    }
    cout<<ans;
    return 0;
}

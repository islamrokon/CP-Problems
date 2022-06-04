#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
void solve()
{
    int n,x;
    cin>>n>>x;
    int arr[n],arr1[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    sort(arr1,arr1+n);
    bool f=1;
    for(int i=0; i<n; i++)
    {
        if(arr1[i]!=arr[i])
        {
            if(!(i>=x||n-i-1>=x))
            {
                f=0;
            }
        }
    }
    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";



}
main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

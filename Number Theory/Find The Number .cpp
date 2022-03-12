#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 100003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
void solve()
{
    vector<int>vec;
    int k,arr[M];
    int unsigned n;
    cin>>k>>n;
    for(int i=0; i<k; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+k);
    for(int i=arr[0]; i<=1015; i++)
    {
        int cnt=0;
        for(int j=0; j<k; j++)
        {
            if(i%arr[j]==0)
            {
                cnt++;
            }
        }
        if(cnt==1)
            vec.push_back(i);
    }
    if(n>1)
    cout<<vec[n-1]<<'\n';
    else
        cout<<vec[n]<<'\n';
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

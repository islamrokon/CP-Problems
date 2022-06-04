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
    string str;
    cin>>str;
    int cnt=0,cnt1=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='A' || str[i]=='C')
        {
            cnt++;
        }
        else
            cnt1++;
    }
    if(cnt==cnt1)
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

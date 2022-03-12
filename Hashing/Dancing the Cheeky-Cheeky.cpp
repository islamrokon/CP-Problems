#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<int> lps(string s)
{
    vector<int>lp;
    lp.resize(s.length()+1,0);
    for(int i=1; i<(int)s.length(); i++)
    {
        int j=lp[i-1];
        while(j>0 && s[i]!=s[j])
        {
            j=lp[j-1];
        }
        if(s[i]==s[j])
            j++;
        lp[i]=j;
    }
    return lp;
}
void solve()
{
    string str;
    cin>>str;
    vector<int>vec;
    vec=lps(str);
    for(auto a:vec)
        cout<<a<<" ";
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

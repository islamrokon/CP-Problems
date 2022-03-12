#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
vector<int> lps(string &s)
{
    vector<int>vec(s.length());
    for(int i=1; i<(int)s.length(); i++)
    {
        int j=vec[i-1];
        while(j>0 && s[i]!=s[j])
            j=vec[j-1];
        if(s[i]==s[j])
            j++;
        vec[i]=j;
    }
    return vec;
}
void solve()
{
    string s1,s2;
    int cnt=0;
    cin>>s1>>s2;
    vector<int>v=lps(s2);
    int i=0,j=0;
    while(i<(int)s1.length())
    {
        if(s1[i]==s2[j] || s1[i]=='?')
            ++i,j++;
        else
        {
            if(j!=0)
                j=v[j-1];
            else
                ++i;
        }
        if(j==(int)s2.length())
        {
            cnt++;
            j=v[j-1];
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    fast;
    int t=1;
    while(t--)
    {
        solve();
    }
}

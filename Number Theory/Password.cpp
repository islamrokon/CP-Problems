#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
bool vis[M];
vector<int> lps(string & s)
{
    vector<int>vec(s.length());
    // unordered_map<int,int>ump;
    for(int i=1; i<(int)s.length(); i++)
    {
        int j=vec[i-1];
        while(j>0 && s[i]!=s[j])
            j=vec[j-1];
        if(s[i]==s[j])
            j++;
        vec[i]=j;
        if(i)
            vis[vec[i-1]] = true;
    }
    return vec;
}
int solve()
{
    string str;
    cin>>str;
    bool flg=0,fl=0;
    int n=(int)str.length();
    vector<int> v=lps(str);
    for (int i = v[n-1]; i; i = v[i-1])
        if (vis[i])
        {
            str[i] = 0;
            fl=1;
            //return 0;
        }
    if(fl==0)
        cout<<"Just a legend";
    else
    {
        for(int i=0; i<(int)str.length(); i++)
        {
            if(str[i]=='\0')
                break;
            cout<<str[i];
            flg=1;
        }
    }

    return 0;
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

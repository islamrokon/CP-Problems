#include<bits/stdc++.h>
#define TC 11 to; cin >> to; for (11 cc=1; cc<=to; cc+)
#define ll unsigned long long
#define MAX 100005
#define base 53
using namespace std;
ll po[MAX];
void init()
{
    po[0]=1;
    for (int i=1; i<MAX; i++)
        po[i]=po[i-1]*base;
}
void preHash (string &s,vector<ll>&pre)
{
    ll hashval=0;
    pre.push_back(hashval);
    for (int i=0;i<s.size();i++)
    {
        ll val;
        if (s[i]<='Z')
            val = s[i]-'A'+1;
        else
            val=s[i]-'a'+27;
        hashval=hashval*base+val;
        pre.push_back(hashval);
    }
}
int suffixpalindrome(string &s,vector<ll>&pre)
{
    ll hashval=0;
    int j,res;
    j=res=s.size()-1;
    for (int i=s.size()-1;i>=0;i--)
    {

        ll val;
        if(s[i]<='Z' )
            val = s[i]-'A'+1;
        else
            val=s[i]-'a'+27;
        hashval=hashval* base + val;
        ll phval=pre[j+1]-(pre[i]*po[j-i+1]);
        if (hashval==phval)
            res=min(res,i);
    }
    return res;
}
int main( )
{
    init();
    string s;
    while(cin>>s)
    {
        vector<ll>pre;
        preHash(s,pre) ;
        ll n=suffixpalindrome(s,pre);
        for (int i=n-1;i>=0;i--){
            s.push_back(s[i]);
        }
        cout<<s<<endl;
    }
    return 0;
}


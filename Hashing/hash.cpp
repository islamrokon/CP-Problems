#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define MOD 1000000007
#define base 26
using namespace std;
ll pH[M+5],po[M];
void preprocess(string &s)
{
    pH[0]=s[0]-'a';
    po[0]=1;
    for(int i=0; i<s.size(); i++)
    {
        pH[i]=((pH[i-1]*base)+(s[i]-'a'))%MOD;
        po[i]=po[i-1]*base%MOD;
    }
     for(int i=0; i<s.size(); i++)
         cout<<pH[i]<<" ";
}
ll getHash(ll L,ll R)
{
    if(L==0) return pH[R];
    return ((pH[R]-(pH[L-1]*po[L-R+1])%MOD)+MOD)%MOD;
}
int main()
{
    /*string s1,s2;
    cin>>s1,s2;
    /*int Q;
    cin>>Q;
    while(Q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
    }*/
    string str;
    cin>>str;
    preprocess(str);
    int ans=getHash(3,5);
    cout<<endl;
    cout<<ans;
    return 0;
}

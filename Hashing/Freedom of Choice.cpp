#include<iostream>
#include<unordered_set>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10005
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define base 157
#define MOD 1000000007
using namespace std;
unordered_set<ll>us;
ll p[M];
int start,ending;
void prehashval(string &s,ll *h)
{
    h[0]=(s[0]-'A'+1)%MOD;
    for(int i=1; i<s.size(); i++)
    {
        h[i]=(h[i-1]*base+s[i]-'A'+1)%MOD;
        //cout<<h[i]<<endl;
    }
}
ll hashvalcheck(string &cs,int m,ll *hc,bool x)
{
    //us.clear();
    ll hval=hc[m];
    if(us.find(hval)!=us.end())
    {
        //cout<<hval<<endl;
        start=-1;
        ending=m;
        return hval;
    }
    if(!x)
        us.insert(hval);
    for(int i=m+1; i<cs.size(); i++)
    {
        hval=((hc[i]-hc[i-m-1]*p[m+1])%MOD+MOD)%MOD;
        if(!x)
        {
            //cout<<hval<<" ";
            us.insert(hval);
        }
        if(x)
            if(us.find(hval)!=us.end())
            {
                //cout<<hval<<endl;
                start=i-m-1;
                ending=i;
                return hval;
            }
    }
    return 0;
}
int main()
{
    fast;
    p[0]=1;
    for(int i=1; i<M; i++)
        p[i]=(p[i-1]*base)%MOD;
    ll h1[M],h2[M];
    int n;
    //cin>>n;
    string str,str1;
    cin>>str>>str1;
    prehashval(str,h1);
    prehashval(str1,h2);
    int r=str.size()-1;
    int l=0,mid;
    ll ans=0,temp=0;
    while(l<=r)
    {
        mid=(l+r+1)/2;
        // cout<<"MID"<<mid<<endl;
        hashvalcheck(str,mid,h1,0);
        ans=hashvalcheck(str1,mid,h2,1);
        //cout<<ans<<endl;
        if(ans>0)
        {
            // cout<<ans<<endl;
            temp=ans;
            if(mid==str.size()-1)
                break;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    string st;
    //cout<<start<<" "<<ending<<endl;
    if(start==-1 && ending ==0)
        cout<<str[0];
    else
    {
        for(int i=start+1; i<=ending; i++)
            st+=str1[i];
        cout<<st;
    }
    return 0;
}

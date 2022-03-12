#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int cnt[M],cas=1;
bool vis[M];
ll temp;
string str,str1;
vector<int>vec,vec1;
void backtrack(int siz)
{
    if(siz==0)
    {
        ll sum = 0;
        int base = 1;
        for(int i=str1.size();i>=0;i--)
        {
            if(str1[i]=='1')
                sum+= base;
            base=base*2;
           //cout<<a;
           //cout<<sum<<endl;
        }
      // cout<<endl;
        //vec1.push_back(sum);
        //cout<<sum<<endl;
       //cout<<str1<<endl;
       if(sum>temp){
        cout<<"Case "<<cas++<<": "<<sum<<endl;
        exit(0);
       }
        return;
    }
    for(int j=str.size(); j>=0; j--)
    {
        if(vis[j]==0)
        {
            vis[j]=1;
            str1+=str[j];
            backtrack(siz-1);
            str1.pop_back();
            vis[j]=0;
        }
    }
}
void solve()
{
    ll n,k=0;
    cin>>n;
    temp=n;
    while(n>0)
    {

        if(n%2==0)
        {
            cnt[0]++;
            str+='0';
        }
        else{
          cnt[1]++;
          str+='1';
        }
        n=n/2;
        k++;
    }
    if(temp%2!=0 ){
    cnt[0]++;
    k=k+1;
    }
    str[str.size()]='0';
    //cout<<k;
    //cout<<str.size();
    backtrack(str.size()+1);
    sort(vec1.begin(),vec1.end());
    ll l,r,mid;
    l=0;
    r=vec1.size()-1;
   /* for(auto a:vec1){
        cout<<a<<endl;
    }*/
  /*  while(l<r){
        mid=(l+r)/2;
        if(temp>=vec1[mid])
            l=mid+1;
        else
           r=mid;
    }
   //cout<<"Case "<<cas++<<": "<<vec1[l]<<endl;
   //cout<<vec1[l]<<endl;
    vec1.clear();
    vec.clear();
    cnt[0]=0;
    cnt[1]=0;*/
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

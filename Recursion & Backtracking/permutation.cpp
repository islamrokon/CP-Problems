#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<string>vec;
string str;
int k,cas=1,cnt;
bool vis[10];
void backtrack(int rem,int n)
{
    if(rem==0)
    {
        vec.push_back(str);
        return;
    }
    for(int i=0; i<n; i++)
    {
        cout<<"str before add:"<<str<<"  i:"<<i<<endl;
        if(vis[i]==0)
        {
            str+='A'+i;
            cout<<"str after add:"<<str<<" i:"<<i<<endl;
            vis[i]=1;
            backtrack(rem-1,n);
            vis[i]=0;
            str.pop_back();
             cout<<"str after delete:"<<str<<" rem:"<<rem<<endl;
        }
    }
}
int main()
{
    fast;
    int n,t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>k;
        cout<<"Case "<<cas++<<":\n";
        backtrack(n,n);
    }
    for(auto a:vec){
        cout<<a<<endl;
    }
}

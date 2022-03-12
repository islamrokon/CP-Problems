#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int arr[25],n,ans,t,ans1,m;
vector<int>vec,v;
void backtrack(int i,int s)
{
    if(i==t)
    {
        if(s>m&&s<=n)
        {
            m=s;
            v=vec;
        }
        return;
    }
    vec.push_back(arr[i]);
    backtrack(i+1,s+arr[i]);
    vec.pop_back();
    backtrack(i+1,s);
}
int main()
{
    fast;
    while(cin>>n)
    {
        m=-M;
        cin>>t;
        for(int i=0; i<t; i++)
        {
            cin>>arr[i];
        }
        backtrack(0,0);
      /*  for(auto a:v)
            cout<<a<<" ";
        cout<<"sum:"<<m<<endl;*/

    }
}

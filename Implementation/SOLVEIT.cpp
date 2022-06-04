#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
int main()
{
    int n,k,y,q;
    cin>>n>>q;
    int arr[n+1]= {0};
    int ar[n];
    arr[0]=1;
    vector<int>vec;
    vector<int>:: iterator it;
    for(int i=0; i<q; i++)
    {
        cin>>k,cout<<" ",cin>>y;
        if(arr[y]==-1 && y>=k)
            vec.push_back(y);
        else if(y>=k)
            vec.push_back(-1);
    }
    for(it=vec.begin();it!=vec.end();it++)
        cout<<*it<<"\n";
}

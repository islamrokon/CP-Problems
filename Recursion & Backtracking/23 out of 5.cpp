#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll position[15];
int arr[5];
int check=0;
int vis[20];
void backtrack(int rem,int ans)
{
    if (ans==23&&rem==0)
    {
        check = 1;
        return;
    }
    for(int i=0; i<5; i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            cout<<i<<" "<<ans<<" "<<arr[i]<<endl;
            backtrack(rem-1,ans+arr[i]);
            backtrack(rem-1,ans-arr[i]);
            backtrack(rem-1,ans*arr[i]);
            vis[i]=0;
        }
    }
}
int main()
{
    while (true)
    {
        for(int i=0; i<5; i++)
            cin>>arr[i];
        if(arr[0]==0)
            break;
        check = 0;
        for(int i = 0; i < 5; i++)
        {
            vis[i] = 1;
            backtrack(4,arr[i]);
            vis[i] = 0;
        }
        if(check==1)
            cout <<"Possible"<<'\n';
        else
            cout <<"Impossible"<<'\n';
    }
    return 0;
}

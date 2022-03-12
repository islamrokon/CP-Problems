#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int main()
{
    fast;
    int arr[20],sum=0,n,k,temp=0,ok=0;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int msk=0; msk<(1<<n); msk++)
    {
       // cout<<"ok"<<endl;
        for(int i=0; i<n; i++)
        {
            if(msk &(1<<i))
            {
                temp+=arr[i];
            }
        }
       // cout<<temp<<endl;
        temp*=k;
        if(temp==sum)
        {
            ok=1;
            cout<<"true\n";
             break;
        }
        temp=0;

    }
    if(ok==0)
    {
        cout<<"false\n";
    }

}

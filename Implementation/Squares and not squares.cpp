#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll as[200000];
ll bs[200000];
ll cs[200000];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>as[i];
    }
    for(int i=0; i<n; i++)
    {
        int low=0,high=32000;
        while(high-low>1)
        {
            int mid=(low+high)/2;
            if(mid*mid<=as[i])
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        cs[i]=min(as[i]-low*low,high*high-as[i]);
        if(as[i]==0)
        {
            bs[i]=2;
        }
        else if(cs[i]==0)
        {
            bs[i]=1;
        }
        else
        {
            bs[i]=0;
        }
    }
    sort(cs,cs+n);
    sort(bs,bs+n);
    if(cs[n/2]>0)
    {
        ll sum=0;
        for(int i=0; i<n/2; i++)
        {
            sum+=cs[i];
        }
        cout<<sum<<"\n";
    }
    else
    {
       ll sum=0;
        for(int i=0; i<n/2; i++)
        {
            sum+=bs[i];
        }
        cout<<sum<<"\n";
    }
    return 0;
}

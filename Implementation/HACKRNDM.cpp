#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main()
{
    int n,k,cnt=0;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        int flag=0,mid;
        int lb=0,ub=n-1;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            if(arr[mid]==arr[i]+k)
            {
                flag=1;
                break;
            }
            else if(arr[mid]>arr[i]+k)
                ub=mid-1;
            else
                lb=mid+1;
        }
        if(flag==1)
            cnt++;
    }
   cout<<cnt;
    return 0;
}


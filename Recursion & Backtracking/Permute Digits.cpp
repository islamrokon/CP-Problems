#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int cnt[20],arr[20];
ll backtrack(int flag,int rem,int cur)
{
    if(rem==0)
        return 0;
    int from=9;
    if(flag==0)
        from=arr[cur];
    for(int i=from; i>=0; i--)
    {
        if(cnt[i]>0)
        {
            //cout<<i<<endl;
            cnt[i]--;
            ll ans;
            if(flag)  //we are securing the place of the digits here then we are going to the for loop by backtracking one by one from last function.
                ans=backtrack(1,rem-1,cur-1);
            else if(i<arr[cur])
                ans=backtrack(1,rem-1,cur-1);
            else
                ans=backtrack(0,rem-1,cur-1);
            cnt[i]++;
            if(ans>=0)
            {
                ll temp=i;
                for(int j=0; j<cur; j++)
                    temp*=10;
                ans+=temp;
                cout<<cur<<" "<<ans<<endl;
                return ans;
            }
        }

    }
    return -1;
}
main()
{
    fast;
    ll a,b;
    int tot=0;
    cin>>a>>b;
    while(a>0)
    {
        int d=a%10;
        cnt[d]++;
        a/=10;
        tot++;
    }
    int dig=0;
    while(b>0)
    {
        int d=b%10;
        arr[dig++]=d;
        b/=10;
    }
    ll ans;
    if(tot<dig)
        ans=backtrack(1,tot,tot-1);
    else
        ans=backtrack(0,tot,tot-1);
    //cout<<ans;
}

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int m,arr[40];
void backtrack(int cur,int last,vector<int>&vec,int sum)
{
    if(cur>last)
    {
        vec.push_back(sum);
        return;
    }
    backtrack(cur+1,last,vec,sum);
    sum+=arr[cur];
    sum%=m;
    backtrack(cur+1,last,vec,sum);
}
main()
{
    fast;
    int n;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        arr[i]%=m;
    }
    vector<int>vec1,vec2;
    backtrack(1,n/2,vec1,0);
    backtrack(n/2+1,n,vec2,0);
    sort(vec2.begin(),vec2.end());
    int ans=0;
    for(auto a:vec1)
    {
        int l=0,r=vec2.size()-1;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(vec2[mid]+a<m)
                l=mid;
            else
                r=mid-1;
        }
        int b=vec2[l];
        ans=max(ans,a+b);
        b=vec2.back();
        ans=max(ans,a+b-m);
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll n,q,a,b,l,r,mid,p;
vector<pair<ll,ll>>vec;
vector<ll>vec1;
int arr[50005];
int srch(int m)
{
    l=0;
    r=n;
    mid=(l+r+1)/2;
    while(l<=r)
    {
        if(m>=vec[mid].first)
        {
          vec1.push_back(vec[mid].second);
          l=mid;
        }
        else
            r=mid-1;
    }
    vec1.push_back(vec[l].second);
    return l;
}
void solve()
{
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(),vec.end());
    /*for(int i=n-1;i>=0;i--){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }*/
    while(q--)
    {
        cin>>p;
        int x=srch(p);
        l=0;
        r=vec1.size();
        sort(vec1.begin(),vec1.end());
        while(l<=r){
            mid=(l+r)/2;
            if(p>=vec1[mid]){
                l=mid;
            }
            else
                r=mid-1;
        }
        if(x>l)
            cout<<l<<"\n";
        else
            cout<<x<<"\n";
            vec1.clear();
    }
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


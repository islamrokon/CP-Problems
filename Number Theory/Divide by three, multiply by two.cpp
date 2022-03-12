#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MOD 1000003999
using namespace std;
void solve()
{
    ///here we are doing is dividing the biggest number into two part where 1st part will be calculated from multiple by 3 and divide by 2 and the 2nd half will be calculated from divide by 3 and multiple by 2
    unordered_map<ll,ll>ump;
    vector<ll>vec,vec1;
    int n;
    cin>>n;
    ll arr[n+2];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        ump[arr[i]]++;
    }
    sort(arr,arr+n);
    //cout<<arr[n-1];
    ll tmp,tmp1;
    vec.push_back(arr[n-1]);
    if(ump.find((arr[n-1]/3))!=ump.end() && arr[n-1]%3==0)
    {
        tmp=arr[n-1]/3;
        vec.push_back(tmp);
        ump.erase(tmp);
        for(int i=0; i<n; i++)
        {
            if(ump.find(tmp/3)!=ump.end())
            {
                tmp/=3;
                vec.push_back(tmp);
                ump.erase(tmp);
            }
            else if(ump.find(tmp*2)!=ump.end())
            {
                tmp*=2;
                vec.push_back(tmp);
                ump.erase(tmp);
            }
        }
    }
    /*for(auto a:ump){
        cout<<a.first<<" ";
    }*/
    if(ump.find((arr[n-1]/2))!=ump.end() && arr[n-1]%2==0)
    {
        tmp1=arr[n-1]/2;
        vec1.push_back(tmp1);
        ump.erase(tmp1);
        for(int i=0; i<n; i++)
        {
            if(ump.find(tmp1/2)!=ump.end())
            {
                tmp1/=2;
                vec1.push_back(tmp1);
                ump.erase(tmp1);
            }
            else if(ump.find(tmp1*3)!=ump.end())
            {
                tmp1*=3;
                vec1.push_back(tmp1);
                ump.erase(tmp1);
            }
        }
    }
    reverse(vec1.begin(),vec1.end());
    for(auto a:vec)
    {
        vec1.push_back(a);
    }
    for(auto x:vec1)
     {
         cout<<x<<" ";
     }
}
int main()
{
    fast;
    int t=1;
    while(t--)
    {
        solve();
    }
}

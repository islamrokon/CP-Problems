#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll n, k;
ll x;
vector < ll > a;
bool check(ll x)
{
    ll moves=0;
    for (int i=n/2; i<n; i++)
    {
        if (x-a[i]>0){
            moves+=x-a[i];
             cout<<"move:"<<moves<<endl;}
        if (moves>k)
            return false;
    }
    if (moves<=k)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll small=1;
    ll big=2000000000;
    while (small!=big)
    {
        ll mid=(small+big+1)/2;
        cout<<"mid:"<<mid<<endl;
        if (check(mid))
        {
            cout<<"small:"<<mid<<endl;
            small=mid;
        }
        else
        {

            big=mid-1;
            cout<<"big:"<<big<<endl;
        }
    }
    cout<<small;
}

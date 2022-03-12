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
    int n;
    cin>>n;
    ll a;
    vector<ll> ans;
    multiset<ll> st;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a;
            st.insert(a);
        }
    }
    auto it=st.end();
    it--;
    ans.push_back(*it);
    st.erase(it);
    for(int i=1; i<n; i++)
    {
        if(st.size()>0)
        {
            auto it=st.end();
            it--;
            //cout<<*it<<" ";
            for(ll j=0; j<ans.size(); j++)
            {
                ll x=__gcd(*it,ans[j]);
                auto itt= st.find(x);
                if(itt!=st.end())
                    st.erase(itt);
                itt= st.find(x);
                if(itt!=st.end())
                    st.erase(itt);
            }
            ans.push_back(*it);
            st.erase(it); ///it's erasing only one value.
        }
    }
    for(auto a:ans)
        cout<<a<<" ";
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

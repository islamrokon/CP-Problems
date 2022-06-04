#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main()
{
    int n,cnt=0,t;
    vector<int>v;
    while(cin>>n)
    {
        if(n==-1)
        {
            if(cnt%2==0){
                t=(cnt/2)-1;
                cout<<v[t]<<"\n";
                v.erase(v.begin()+t-1);
                cnt--;
            }
            else{
                t=(cnt/2);
                cout<<v[t]<<"\n";
                v.erase(v.begin()+t-1);
                cnt--;
            }

        }
        else if(n==0)
        {
            v.clear();
            cout<<"\n";
            cnt=0;

        }
        else
        {
            v.push_back(n);
            cnt++;
        }
    }
}

#include<iostream>
#include<set>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int main()
{
    ll n,m,val,a=0;
    multiset<int>s;
    multiset<int>:: iterator it;
    string str;
    cin>>n>>m;
    while(m--)
    {
        cin>>str;
        if(str=="L")
        {
            cin>>val;
            for(it=s.begin(); it!=s.end(); it++) //O(10*9)
            {
                if(val>=*it)
                {
                    a++;
                }
            }
            cout<<val+a<<"\n";
            a=0;
        }
        else if(str=="D")
        {
            cin>>val;
            s.insert(val);
        }
    }
}

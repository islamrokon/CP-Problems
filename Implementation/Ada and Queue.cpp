#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
char str[100];
int n;
bool flag=0;
deque<int>q;
void solve()
{
    cin>>str;
    if(str[0]=='t')
    {
        cin>>n;
        if(flag==1)
        {
            q.push_back(n);
        }
        else
            q.push_front(n);
    }
    else if(str[0]=='f')
    {
        if(q.empty())
        {
            cout<<"No job for Ada?\n";
        }
        else
        {
            cout<<q.front()<<"\n";
            q.pop_front();
        }
    }
    else if(str[0]=='p')
    {
        cin>>n;
        if(flag==1)
        {
            q.push_front(n);
        }
        else
            q.push_back(n);
    }
    else if(str[0]=='r')
    {
        flag=!flag;
    }
    else if(str[0]=='b')
    {
        if(q.empty())
        {
            cout<<"No job for Ada?\n";
        }
        else
        {
            cout<<q.back()<<"\n";
            q.pop_back();
        }
    }
}
main()
{
    fast;
    int q;
    cin>>q;
    while(q--)
    {
        solve();
    }
}

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
    string str;
    cin>>str;
    stack<char>stk;
    stk.push(str[str.length()-1]);
    for(int i=str.length()-2; i>=0; i--)
    {
        if(stk.top()==str[i])
        {
            stk.pop();
            if(stk.empty())
            {
                stk.push(str[i-1]);
                i=i-1;
            }
        }
        else
        {
            stk.push(str[i]);
        }
    }
    while(!stk.empty())
    {
        char x;
        x=stk.top();
        cout<<x;
        stk.pop();
    }

}

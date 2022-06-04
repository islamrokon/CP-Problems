#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main()
{
    int n,x,cnt=0,a=1;
    cin>>n;
    string str;
    stack<int>stk;
    //set<int>s;
    for(int i=0; i<n*2; i++)
    {
        cin>>str;
        if(str=="add")
        {
            cin>>x;
            stk.push(x);
            //s.insert(x);
        }
        else
        {
            if(!stk.empty() && stk.top() == a){
                    ///cout<<"pop "<<stk.top()<<endl;
                stk.pop();
            }
            else
            {
                if(stk.size())
                    cnt++;
                while(!stk.empty()){
                        ///cout<<"top "<<stk.top()<<endl;
                    stk.pop();
                }
            }
            a++;
        }
    }
    cout<<cnt;
}

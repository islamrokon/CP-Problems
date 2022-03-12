#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000005
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int n;
bool vis[20];
vector<int>vec;
bool prime[50];

void backtrack(int rem,int last)
{
    if(rem==0)
    {
        if(prime[1+last]==1)
        {
            cout<<vec[0];
            for(auto a:vec)
            {
                if(a!=vec[0])

                cout<<" "<<a;
            }
            cout<<endl;
        }

    }
    for(int i=2; i<=n; i++)
    {
        if(vis[i]==0 && prime[i+last]==1)
        {
            vis[i]=1;
            vec.push_back(i);
            backtrack(rem-1,i);
            vis[i]=0;
            vec.pop_back();

        }
    }
}
int main()
{
    for(int i=2; i<=40; i++)
    {
        prime[i]=1;
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
                prime[i]=0;
        }
    }
    fast;
    vec.push_back(1);
    vis[1]=1;
    int cas=1;
    while(cin>>n)
    {
        if(cas!=1)cout<<endl;
        cout<<"Case "<<cas++<<":\n";
        backtrack(n-1,1);
    }
}

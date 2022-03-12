#include<bits/stdc++.h>
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
    fast;
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            exit(0);
        }
        if(n<=100){
            cout<<"f91("<<n<<") = "<<91<<"\n";
        }
        else
            cout<<"f91("<<n<<") = "<<n-10<<'\n';
    }
}

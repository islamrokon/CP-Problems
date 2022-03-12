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
int main()
{
    int sum =0,n,i=0;
    int divisor;
    int num[5000];
    cin>>n; ///scanning the value
    cin>>divisor;
    while(n)
    {
        ll tmp=n%10;
        num[i++]=tmp;
        n/=10;
    }
    for(int j=i-1; j>=0; j--)
    {
        sum=(sum*10+num[j])%divisor;
    }
    cout<<sum; ///if sum is 0 then value is divisible by divisor otherwise not.
}

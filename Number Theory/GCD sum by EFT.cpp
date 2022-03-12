///https://youtu.be/khCze6j1vXg
///if we calculate the divisors of n and each divisor exactly how many times comes for gcd(i,n) here i is 1 to n then we calculate the sum of gcd from 1 to n.
///like for 12 divisors are 1,2,3,6,12 here 1*4+2*2+3*2+4*2+6*1+12*1 now lets say gcd is 4 so for 4 here gcd(12,4) and gcd(12,8)
///see txt file line 80.
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
int phi[M];
void phival(int x)
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= x; i++)
        phi[i] = i;

    for (int i = 2; i <= x; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= x; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int getCount(int d,int N)
{
    return phi[N/d];
}
int main()
{
    fast;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        phival(n);
        int res=0;
        for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                int d1=i;
                int d2=n/d1;
                res+=d1*getCount(d1,n);
                if(d1!=d2)
                    res+=d2*getCount(d2,n);
            }
        }
        cout<<res<<endl;
    }

}

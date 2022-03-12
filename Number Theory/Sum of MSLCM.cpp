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
using namespace std;
#define long long long int
int main()
{
    ios_base::sync_with_stdio(false);
    long n;
    while(cin>> n && n)  /// we will get multiple times of a value less than root(n) for n and greater than root(n)
    {
        ///values will come once because (int)n/a(a>root(n))=1.
        long ans=0,a=1;
        while(a<=n)
        {
            //cout<<a<<endl;
            long x=n/a; ///how many times a occurs in n.
            long y=n/x; ///what is the value for a where x*y<=n.
            //cout<<y<<endl;
            ///x is how many times a occurs and y is the value.
            ans+=x*(((a+y)*(y-a+1))/2);  ///here we applied summation formula, which is S = (n*(a + L))/2 here we
            ///calculate n by n=y-a+1 and multiplication x is for problem
            ///like when a becomes 6 for n=10, from 6 to 10 we can calculate 1 for them, means they appears once.
            ///these is not necessary to calculate for 4 and 5 separately because both comes twice for 10.
            ///we can calculate it by x and y.
            ///like a=4 so x=10/4=2, y=10/2=5 so for then we can do it by summation series formula.
            a=++y;
        }
        ans--;
        cout<< ans <<endl;
    }
    return 0;
}

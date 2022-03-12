///https://youtu.be/6KmhCKxFWOs
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
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0) ///a.x+b.y=g
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; /// To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    ///ay1+b(x1−(a/b)·y1)=gcd(a,b).
    ///a.x+b.y=g
    ///x=y1; y=x1-(a/b)·y1.
    ///x1,y1 are from (b,a%b) and x,y are from a.x+b.y
    ///for each x1,y1 we are calculating the previous x,y thus we get the final x,y.
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
// Driver Code
int main()
{
    int x, y, a = 35, b = 15;
    int g = gcdExtended(a, b, &x, &y); ///gcd of a and b.
    cout << "GCD(" << a << ", " << b
         << ") = " << g << endl;
    return 0;
}

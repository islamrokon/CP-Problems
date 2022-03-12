#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 10003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
using namespace std;
// Iterative C++ program to compute modular power
/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, unsigned int y, int p)
{
    int res = 1;	 // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Driver code
int main()
{
    int x = 2;
    int y = 5;
    int p = 13;
    cout << "Power is " << power(x, y, p);
    return 0;
}

// This code is contributed by shubhamsingh10

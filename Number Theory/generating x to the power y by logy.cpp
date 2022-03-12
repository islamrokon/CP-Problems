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
int main()
{
    int x=2;
    int y=6;
    int res = 1;

    // Check till the number becomes zero
    while (y)
    {

        /// If y is odd, multiply x with result 2*2*2(8)*2*2*2(8)=64
        if (y % 2 == 1) ///for odd 2*2(4)*2*2(4)*2(2)=32.
            res = (res * x);

        // y = y/2
        y = y >> 1;

        // Change x to x^2
        x = (x * x);
    }
    cout<< res;
}

///https://stackoverflow.com/questions/31676513/number-theory-algorithms-most-divisors-on-the-segment
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll n, res;
int p, primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59, 61, 67, 71};

ll mul(ll a,ll b)
{
    ///multiplication of a and b. The main reason for this procedure is: if the product is greater
    ///than n, then the function returns 0. This procedure is only a guard against overflow that may happen
    ///otherwise.
    ll res = 0;
    while (b)
    {
        if (b & 1LL)
            res = (res + a);
        if (res >= n)
            return 0;
        a = (a << 1LL); ///multiplied by 2
        b >>= 1LL; ///divided by 2
    }
    return res;
}
void backtrack(int i, int lim, ll val, ll r)
{
    if (r > res)
        res = r; ///number of divisors.
    if (i == p) ///reached the all prime numbers.
        return;
    int d;
    ll x = val;

    for (d = 1; d <= lim; d++)
    {
        //cout<<"prime:"<<primes[i]<<endl;
        x = mul(x, primes[i]); ///multiplication of prime numbers less than n.
        //cout<<"x:"<<x<<endl;
        if (x == 0)   ///x returns 0 means x become greater than n.
            return;
        backtrack(i + 1, d, x, r * (d + 1)); ///every power(d) for the current prime number starts with 1,
        ///which starts for the smaller prime number and goes on by descending (<=) order for the rest
        /// of the prime numbers. like 2^a,3^b,4^c,... where a>=b>=c...
        ///r*(d+1) means we know how to calculate number of divisors from it's prime factorization.
    }
}
int main()
{
    /* Tested for n <= 10^18 */

    p = sizeof(primes) / sizeof(int);

    while (scanf("%llu", &n) != EOF)
    {
        res = 0;
        backtrack(0, 100, 1, 1); ///power cannot be greater than 100 because 2^100 already exceed 64-bit integer.
        printf("Maximum number of divisors of any number less than %llu = %llu\n", n, res);
    }
    return 0;
}


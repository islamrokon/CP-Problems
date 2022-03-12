#include<bits/stdc++.h>
using namespace std;
///calculating the phi value of 1 to n.
int main()
{
    int n=6;
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;
///we find all prime numbers and for each one update the temporary results of all numbers that are divisible by that prime number.
    for (int i = 2; i <= n; i++)
    {
        cout<<i<<" "<<phi[i]<<endl;
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i) ///j+=i targeting the divisor of i.
                phi[j] -= phi[j] / i; ///subtracting the prime factor and it's multiple values.
        }
    }
}

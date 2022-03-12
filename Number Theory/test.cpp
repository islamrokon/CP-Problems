/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// C++ program to demonstrate working of
// extended Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
	// Base Case
	cout<<a<<" "<<b<<endl;
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call

	int gcd = gcdExtended(b%a, a, &x1, &y1);
	cout<<x1<<" "<<y1<<endl;
	//cout<<a<<" "<<b<<" "<<gcd<<endl;

	// Update x and y using results of
	// recursive call
	*x = y1 - (b/a) * x1; ///results
	*y = x1;


	return gcd;
}

// Driver Code
int main()
{
	int x, y, a = 35, b = 15;
	int g = gcdExtended(a, b, &x, &y);

	cout << "GCD(" << a << ", " << b
		<< ") = " << g << endl;
	return 0;
}

// This code is contributed by TusharSabhani


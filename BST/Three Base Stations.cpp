#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int n;
int arr[200020];
double sol[3];
double tmp [3];
bool valid(double d){
	double end = 0;
	int j = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] > end){
			if (j == 3)
				return 0;
			tmp[j++] = d + arr[i];
			end = arr[i] + 2.0 * d;
			//cout<<"end:"<<end<<endl;
		}
	}
	for (int i = 0; i < 3; i++)
		sol [i] = tmp [i];
	return 1;
}
double biSearch (){
	double lo = 0;
	double hi = arr[n-1];
	while (hi - lo > 1e-6){
		double mid = (lo+hi)/2;
		//cout<<"mid:"<<mid<<endl;
		if (valid (mid))
			hi = mid;
		else lo = mid;
	}
	return lo;
}
int main (){

	cin>>n;
	for (int i = 0; i < n; i++)
		cin>>arr[i];
	sort (arr, arr+n);
	printf ("%.6lf\n",biSearch());
	printf ("%.6lf %.6lf %.6lf", sol[0],sol[1], sol[2]);
}

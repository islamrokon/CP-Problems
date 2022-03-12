#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
vector<int>vec;
int sum;
int fun(int a,int n)
{
    if(a!=1 && a%n==0)
    {
        return 0;
    }
    if(a==1)
    {
        sum+=n-1;
        vec.push_back(sum);
        return 0;
    }
    if(a==1 && n==1)
    {
        return 0;
    }
    if(n>a)
    {
        sum+=n/a;
        fun(n%a,a);
    }
    return 0;
}
int main()
{
    int n,i;
    cin>>n;
    if(n==1){
        cout<<'0';
        exit(0);
    }
    i=n-1;
    while(i>0)
    {
        sum=0;
        fun(n-i,n);
        i--;
    }
    sort(vec.begin(),vec.end());
    cout<<vec[0];
}

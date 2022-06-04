#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
char str[100000];
using namespace std;
int n,a[100005],b[100005],cnt,ly;
char s[100005];
bool check(int x)
{
	int now=1;
	for (int i=1;i<=cnt;i++)
	{
		if (now>ly)break;                 //a[]=P ,b[]=*
		if (a[i]-x<=b[now]&&a[i]+x>=b[now])
		{
			int r=max(b[now]+x-abs(b[now]-a[i]),(x+a[i]+b[now])/2);
			while(now<=ly&&b[now]<=r) now++;
		}
	}
	return now>ly;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
	    cin>>s[i];
		if (s[i]=='P')
			a[++cnt]=i;
		else if (s[i]=='*') b[++ly]=i;
	}
	int l=0,r=n*2,mid;
	while(l<=r)
	{
		mid=l+r>>1; //(l+r)/2
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
}

#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n,t,a[N],i,j,s[N],c[N],l[N],r[N],v[N],ans,x,y;
int main()
{
    priority_queue<pii> pq;
    cin>>n;
	for(i=0;i<n;i++)
        cin>>a[i];
	for(i=j=0;i<n;i=j)
    {
		while(a[++j]==a[i]); //where after a[i] all element will counted if they same as a[i], j is continuously increasing by 1 hence it's moving forward to the array.(purpose of this semicolon loop is to find length of an array,string etc)
		s[++t]=a[i];
		c[t]=j-i;
		l[t]=t-1,r[t]=t+1;
		pq.push({c[t],-t});
	}
	while(pq.size())
	{
        t=-pq.top().second;
        pq.pop();
        if(v[t])continue;
        ans++;
        v[t]=1;
        x=l[t],y=r[t];
        l[y]=x,r[x]=y;
        if(l[t]&&s[x]==s[y]){
            c[x]+=c[y];
            v[y]=1;
            pq.push({c[x],-x});
            x=l[y];y=r[y];
            l[y]=x,r[x]=y;
        }
	}
	cout<<ans;
}

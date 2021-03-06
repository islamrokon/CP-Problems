#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define Dpos(n) fixed << setprecision(n)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

double BS(double,double,double,double);
double triangleRatio(double,double,double,double);
using namespace std;
int main()
{
    fast;
    int tc,cn;
    double ab,ac,bc,ratio,ans;
    cin>>tc;
    for(cn=1; cn<=tc; cn++)
    {
        cin>>ab>>ac>>bc>>ratio;
        ans= BS(ab,ac,bc,ratio);
        cout<<"Case "<<cn<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }

}

double triangleRatio(double ab,double ac,double bc,double ad)
{
    double ae,de,s1,s2,largeTriangleArea,smallTriangleArea,trapheziumArea, ratio;
    ae = (ad*ac)/ab;
    de = (ad*bc)/ab;

    s1 = (ab+ac+bc)/2.0;
    s2 = (ad+ae+de)/2.0;
    largeTriangleArea = sqrt(s1 * (s1-ab) * (s1-ac) * (s1-bc));
    smallTriangleArea = sqrt(s2 * (s2-ad) * (s2-ae) * (s2-de));
    trapheziumArea = largeTriangleArea - smallTriangleArea;

    ratio  = smallTriangleArea/trapheziumArea;
    return ratio;
}

double BS(double ab,double ac,double bc,double ratio)
{
    double low,high,ad,mid;
    low=0.0;
    high = ab;

    for(int i=0; i<100; i++)
    {
        mid = (low+high)/2.0;
        ad = mid;

        if(triangleRatio(ab,ac,bc,ad)>ratio)
            high=mid;

        else
            low=mid;
    }

    return ad;

}

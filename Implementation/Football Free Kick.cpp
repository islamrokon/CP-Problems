#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define inf 1<<30
#define F first
#define S second
#define pf printf
using namespace std;
void solve()
{
    int N,K,Q;
    cin>>N>>K>>Q;

    set<pair<int,int> > segment;

    segment.insert(make_pair(1,-1));
    segment.insert(make_pair(K,1));

    segment.insert(make_pair(-inf,-1));
    segment.insert(make_pair(-inf,1));

    segment.insert(make_pair(inf,-1));
    segment.insert(make_pair(inf,1));

    int x,y;

    int hole = 1;

    std::set<pair<int,int> >::iterator itlow,itup;
    while(Q--)
    {
        cin>>x>>y;

        assert(1<=x and x<=N);
        assert(1<=y and y<=N);

        itlow = segment.lower_bound(make_pair(x,-1)) ;
        if((*itlow).S==1)
            itlow--;

        itup = segment.upper_bound(make_pair((*itlow).F,-1)) ;


        if((*itlow).F==(*itup).F)
        {
            segment.erase(itlow);
            segment.erase(itup);
            if(x!=1 and x!=N)
                hole--;
        }
        else if((*itlow).F==x)
        {
            segment.erase(itlow);
            segment.insert(make_pair(x+1,-1 ));

            if(x==1 or x==N)
                hole++;

        }
        else if((*itup).F==x)
        {
            segment.erase(itup);
            segment.insert(make_pair(x-1,1 ));

            if(x==1 or x==N)
                hole++;
        }
        else
        {
            segment.insert(make_pair(x-1,1 ));
            segment.insert(make_pair(x+1,-1 ));
            hole++;
        }


        itlow = segment.find(make_pair(y-1,1)) ;
        itup = segment.find(make_pair(y+1,-1)) ;

        if(itlow!=segment.end() and itup!=segment.end())
        {
            segment.erase(itlow);
            segment.erase(itup);
            hole--;
        }
        else if(itlow!=segment.end())
        {
            segment.erase(itlow);
            segment.insert(make_pair(y,1));

            if(y==1 or y==N)
                hole--;
        }
        else if(itup!=segment.end())
        {
            segment.erase(itup);
            segment.insert(make_pair(y,-1));

            if(y==1 or y==N)
                hole--;
        }
        else
        {
            segment.insert(make_pair(y,-1));
            segment.insert(make_pair(y,1));
            if(y!=1 and y!=N)
                hole++;
        }
        cout<<hole<<"\n";
    }
}

int main()   // freopen("sample.in", "r", stdin);
{
    int t,tcase=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<tcase++<<":\n";
        solve();
    }


}

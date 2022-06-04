#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        set<int>cor[2];
        priority_queue<pair<int,pair<int,int>>>pqq[2];
        cor[0].insert(0);
        cor[1].insert(0);
        cor[0].insert(n);
        cor[1].insert(m);

        pqq[0].push({n,{0,n}});
        pqq[1].push({m,{0,m}});

        while(q--)
        {
            int typ,pnt;
            cin>>typ>>pnt;
            cor[typ].insert(pnt);
            set<int>::iterator itt=cor[typ].find(pnt),pre,post;
            pre=post=itt;
            pre--;
            post++;
            pqq[typ].push({(*itt)-(*pre),{*pre,*itt}});
            pqq[typ].push({(*post)-(*itt),{*itt,*post}});

            ll ans=1;
            for(int i=0; i<2; i++)
            {
                while(!pqq[i].empty())
                {
                    pair<int,pair<int,int>>p=pqq[i].top();
                    int from=p.second.first, too=p.second.second;
                    itt=cor[typ].find(from);
                    itt++;
                    if(*itt!=too)
                    {
                        pqq[i].pop();
                    }
                    else
                    {
                        ans*=p.first;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}

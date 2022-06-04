#include<bits/stdc++.h>
#define N ((int)1e6 + 5)
#define MOD ((int)1e9 + 7)
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAX ((int)1e6 + 5)
#define endl "\n"

using namespace std;



int main()
{
/// problem link: https://www.spoj.com/problems/MINSTOCK/en/
    fastio;
    int n;
    cin>>n;
    priority_queue < pair < int , string > > pqq;
    map < string , int > cost;
    int tmp = 0;
    while(n--){
        tmp++;
        int typ ;
        string str;
        cin>>typ>>str;
        if(typ == 1){
            int val;
            cin>>val;
            cost[str] = val;
            pqq.push({-val , str});
        }
        else if(typ == 2){
            int val;
            cin>>val;
            cost[str] = val;
            pqq.push({-val , str});
        }
        else{
            while(!pqq.empty()){
                pair < int , string > p = pqq.top();
                pqq.pop();
                if(cost[p.second] == -p.first){
                    cout<<p.second<<" "<<tmp<<endl;
                    cost[p.second] = -1;
                    break;
                }
            }
        }
    }
    return 0;
}

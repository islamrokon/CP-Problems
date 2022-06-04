#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
const int MXN = 1e6 + 10;
int n, l, c;
char str[MXN];
vector < pair < char , int > > V, P;
int main()
{
   cin>>str;
    n = strlen(str);
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == str[i - 1])
            continue;
        cout<<str[i-1]<<" "<<i-l<<endl;
        V.push_back({str[i - 1], i - l});
        l = i;
    }
    while (V.size() > 1)
    {
        V[0].y --;
        V.back().y --;
        for (int i = 1; i < (int)V.size() - 1; i++)
            V[i].y -= 2;
        for (auto X : V)
        {
            if (X.y <= 0)
                continue;
            if ((int)P.size() == 0)
            {
                P.push_back(X);
                continue;
            }
            if (P.back().x == X.x)
                P.back().y += X.y;
            else
                P.push_back(X);
        }
        V = P;
        P.clear();
        c ++;
    }
   cout<<c;
}

#include<bits/stdc++.h>
#define ll unsigned long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100005
#define base 31
#define x first
#define y second
using namespace std;
string str[MAX + 5];
char tstr[MAX + 5];
ll h[MAX + 5], po[MAX + 5];
unordered_map<ll, ll> ump;
/// [0, 10^19]

void pre()
{
    po[0] = 1;
    for(int i = 1; i <= MAX; i++)
        po[i] = po[i - 1] * base;
}

ll calcHash(string &s)
{
    ll hval = 0;
    for(auto ch : s)
        hval = (hval * base) + (ch - 'a' + 1);
    return hval;
}

ll changeHash(int strNo, int idxNo, char ch, int m)
{
    ll newHashValue = h[strNo] + ((ch - str[strNo][idxNo]) * po[m - 1 - idxNo]);
    return newHashValue;
}

int main()
{
    fast;
    pre();
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>tstr;
        str[i] = tstr;
        h[i] = calcHash(str[i]);
        ump[h[i]]++;
    }
    ll ans = 0;
    /// 25 * N * M
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(char k = 'a'; k <= 'z'; k++)
            {
                if(k == str[i][j])
                    continue;
                ll changedHashValue = changeHash(i, j, k, m);
                if(ump.find(changedHashValue) != ump.end())
                {

                    ans += ump[changedHashValue];
                     //cout<<str[i]<<" "<<ans<<endl;
                }

            }
        }
    }
    cout<<ans/2; ///lets assume strings are a,b so for a cnt will increase when it will get c same goes for c but pair is same means (a,c) and (c,a) same thing counting twice that's why divide by 2
    return 0;
}

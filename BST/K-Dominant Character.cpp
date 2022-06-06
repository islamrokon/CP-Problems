#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int check(string s, int K)
{
    for (int ch = 0; ch < 26; ch++)
    {
        char c = 'a' + ch;
        int last = -1;
        bool found = true;
        for (int i = 0; i < K; i++)
            if (s[i] == c)
                last = i;
        if (last == -1)
            continue;
        for (int i = K; i < s.size(); i++)
        {
            if (s[i] == c)
                last = i;
            if (last <= (i - K))
            {
                found = false;
                break;
            }
        }
        if (found)
            return 1;
    }
    return 0;
}
main()
{
    fast;
    string s;
    cin>>s;
    int low = 1, high = s.size();
    int ans;
    while (low <= high)
    {
        int mid = (high + low) >> 1;
        if (check(s, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout<<ans;
    return 0;
}


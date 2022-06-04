#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
int main()
{
    map<string, int> mp;

    int q;
    cin >> q;
    while (q--)
    {
        int op;
        string s;
        cin >> op;
        if (op == 0)
        {
            int x;
            cin >> s >> x;
            mp[s] = x;
        }
        else if (op == 1)
        {
            cin >> s;
            if (!mp.count(s))
            {
                cout << 0 << endl;
            }
            else
            {
                cout << mp[s] << endl;
            }
        }
        else if (op == 2)
        {
            cin >> s;
            mp.erase(s);
        }
        else
        {
            string l, r;
            cin >> l >> r;
            for (auto it = mp.lower_bound(l); it != mp.upper_bound(r); it++)
            {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}


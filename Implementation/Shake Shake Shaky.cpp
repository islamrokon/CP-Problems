#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll n, k, l, r, mid, ans;
vector<int> arr;
bool can(int mid)
{
    int tmpK = k;
    for(int i = n - 1; i >= 0; i--)
    {
        tmpK -= (arr[i]/mid);
        if(tmpK <= 0)
            return true;
    }
    return false;
}
int main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        arr.clear();
        arr.resize(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        l = 1;
        r = arr.back() + 1;
        ans = 0;
        while(l <= r)
        {
            mid = (l + r) / 2;

            if(can(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout <<ans<<"\n";
    }
    return 0;
}

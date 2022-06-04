
#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
unordered_map<int, int> cnt;
int a[100500];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l;
    l = 0;
    set <int> s;
    for (int i = 1; i < k; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1)
            s.insert(a[i]);
        else
            s.erase(a[i]);
    }
    cnt[0]++;
    for (int i = k; i <= n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1)
            s.insert(a[i]);
        else
            s.erase(a[i]);
        cnt[a[l]]--;
        if (cnt[a[l]] == 1)
            s.insert(a[l]);
        else
            s.erase(a[l]);
        l++;
        if (s.empty())
            cout << "Nothing\n";
        else
            cout << *s.rbegin() << '\n';
    }
    return 0;
}

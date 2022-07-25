#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e9+8
using namespace std;
const int N = 2*1e5+5;
int dp[N], arr[N], h[N], aux[N];
void solve()
{
    int n;
    for(int i = 1; i <= n; i++){
        cin>>h[i]>>arr[i];
    }
    for(int i = 1; i <= n; i++){
        aux[i] = MAX;
    }
    aux[0] = -MAX;
    for(int i = 1; i <= n; i++){
        int cur = h[i];
        int l = 0, r = n;
        while(l < r){
            int mid = (l+r+1)/2;
            if(aux[mid] < cur) l = mid;
            else r = mid - 1;
        }
        int ans = l + 1;
        dp[i] = ans;
        aux[ans] = min(aux[ans], cur);
    }
}
int main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
}

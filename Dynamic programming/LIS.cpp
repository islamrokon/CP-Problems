/// 15th class of synapse.
#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000003
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 253
#define MAX 1e9
using namespace std;
const int N = 1e8;
int arr[N], aux[N], dp[N], a[N];
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        aux[i] = MAX;
    }
    aux[0] = -MAX;
    int s = 0, tmp = 0, val;
    for(int i = 1; i <= n; i++)
    {
        int cur = arr[i];
        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l+r+1)/2;
            if(aux[mid] < cur) l = mid;
            else r = mid - 1;
        }
        int ans = l + 1;
        dp[i] = ans; /// LIS for each value.
        if(tmp < ans)
        {
            val = arr[i];
            tmp = ans;
        }
        aux[ans] = min(aux[ans], cur);
        s = l;
    }
    /*for(int i = 1; i <= s + 1; i++){
        cout<<aux[i]<<" ";
    }
    cout<<endl;
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }*/
    //cout<<tmp<<endl;
    cout<< val<<" ";
    for(int i = n-1; i > 0; i--) /// from n-1 to 1 because of increasing subsequence
    {                       /// that means array increase from left to right.
        if(arr[i] < val && dp[i] == tmp - 1)
        {
            cout<<arr[i]<<" ";
            val = arr[i];
            tmp--;
        }
    }
}

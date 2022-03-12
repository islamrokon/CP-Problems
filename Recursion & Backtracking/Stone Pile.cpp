#include <bits/stdc++.h>
using namespace std;
int n;
int arr[22];
int sum = 0;
int ans;
void backtrack(int i, int s)
{
    cout<<s<<endl;
    if(i == n)
    {
        cout<<"ok:"<<s<<endl;
        ans = min(ans, abs(sum - s*2));
        return;
    }
    backtrack(i+1, s);
    cout<<"i:"<<i<<endl;
    backtrack(i+1, s+arr[i]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    ans = sum;
    backtrack(0, 0);
    //printf("%d\n",ans);
    return 0;
}

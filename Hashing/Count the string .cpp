#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 2e5 + 5;
int t, n, ne[N];
char s[N];
int getNext()
{
    ne[1] = 0;
    int ans = n;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
        int t = j;
        cout<<s[i]<<endl;
        while (t)
        {
            ans++;
            t = ne[t];
        }
        cout<<ans<<endl;
        ans %= 10007;
    }
    return ans;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s + 1);
        printf("%d\n", getNext());
    }
    return 0;
}

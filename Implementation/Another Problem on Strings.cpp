#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
using namespace std;
ll k,n,cnt,a[1000009];
string str;
int main()
{
    cin>>k>>str;
    a[0]=1;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='1'){
            cnt++;
        }
        if(cnt>=k){
            n=n+a[cnt-k];
            cout<<a[cnt-k]<<endl;
        }
        cout<<"cnt:"<<cnt<<endl;
        a[cnt]++;
        cout<<"a[cnt]"<<a[cnt]<<endl;
    }
    cout<<n;
}

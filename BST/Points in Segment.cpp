#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int srch(int n,int b){
    int L=0,R=n;
    while(L<R){
        int mid=(L+R+1)/2;
        if(arr[mid]<=b) L=mid;
        else R=mid-1;
    }
    return L;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    arr[0]=0;
    sort(arr+1,arr+n+1);
    while(q--){
        int a,b;
        cin>>a>>b;
        int R=srch(n,b) , L=srch(n,a-1);
        cout<<R-L<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define eps (1e-8)
using namespace std;
ll fun(int x){
    return 1LL*x*x+1;

}
int main()
{

    int q;
    cin>>q;
    while(q--){
        int val;
        cin>>val;
        int L=0, R=1e5;
        while(L<R){
            int mid=(L+R)/2;
            if(fun(mid)<val)  L=mid+1;
            else R=mid;

        }
        if(fun(L)==val) cout<<L<<endl;
        else cout<<"-1\n";

    }
}

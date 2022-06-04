#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main()
{
    vector<int> vec;
    int n;
    cin>>n;
    int arr[n],ar=0,a=1,b=0,c=0,cnt=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        vec.push_back(arr[i]);
    }
    while(!vec.empty())
    {
        for(int i=1; i<vec.size(); i++)
        {
            if(vec[i]==vec[i-1])
            {
                a++;
                if(a>b)
                {
                    b=a;
                    c=i;
                }
            }
            else
            {
                a=1;
            }
            ar=b;
        }
        if(ar==1)
        {
            cnt=n;
            break;
        }
        cout<<"B:"<<b<<"\n";
        cout<<"C:"<<c<<"\n";
        for(int i=c-b+1;i<=c;i++){
                cout<<"I:"<<i<<"val:"<<vec[2]<<endl;
        vec.erase(vec.begin()+i);
        }
        cout<<vec[0]<<" "<<vec[1]<<endl;
        cout<<vec[2]<<" "<<vec[3]<<endl;
        break;
       // vec.pop_back();
        b=0;
        cnt++;

    }
    cout<<cnt;

}

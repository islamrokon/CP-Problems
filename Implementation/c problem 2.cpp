#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mn,mx;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    mn=arr[0];
    for(int i=1; i<n; i++)
    {
        if(mn>arr[i]){
            mn=arr[i];
        }
        else
            mn=mn;
    }
    mx=arr[0];
    for(int i=1;i<n;i++){
        if(mx<arr[1]){
            mx=arr[1];
        }
        else
            mx=mx;
    }

    cout<<"Minimum Number: "<<mn<<endl;
    cout<<"Maximum Number: "<<mx<<endl;
}

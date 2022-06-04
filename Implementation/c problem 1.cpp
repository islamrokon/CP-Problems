#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=arr[i]+sum;
    }
    float avg=sum/n;
    cout<<avg;
    return 0;
}

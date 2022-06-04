#include<iostream>
using namespace std;
int main()
{
    int m,s,b,a,i,j;
    cin>>m>>s;
    a=s;
    b=s;
    for(i=1; i<=s; i++)
    {
        for(j=1; j<=s; j++)
        {
            if(i+j==s)
            {
                if(i<a && j<b)
                {
                    a=i;
                    b=j;
                }
            }
        }
    }
    cout<<i<<j;


}

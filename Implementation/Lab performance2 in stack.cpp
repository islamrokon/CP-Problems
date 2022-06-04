#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    stack<char>stk;
    int n=str.length();
    for(int i=0; i<=n; i++)
    {
        if(str[i]=='(')
        {
            stk.push(str[i]);
        }
        else if(str[i]==')')
        {
            if(stk.top()!='(')
            {
                cout<<"Expression is Invalid";
                break;
            }
            stk.pop();

        }
        if(i==n)
        {
            if(stk.top()=='(')
            {
                cout<<"Expression is Valid";
            }
            else
                cout<<"Expression is valid";
        }
    }
}



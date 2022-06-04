#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int n = str.length();
    string temp;
    bool x = false;
    bool y = false;
    for (int i=0; i<n; i++)
    {
        if (x == true && str[i] == '\n')
        {
            x = false;
        }
        else if  (y == true && str[i] == '*' && str[i+1] == '/')
        {
            y = false,  i++;
        }
        else if (x || y)
        {
            continue;
        }
        else if (str[i] == '/' && str[i+1] == '/')
        {
            x = true, i++;
        }
        else if (str[i] == '/' && str[i+1] == '*')
        {
            y = true,  i++;
        }
        else
        {
            temp =temp + str[i];
        }
    }
    cout<<temp;

}

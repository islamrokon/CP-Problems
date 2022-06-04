#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
    ofstream file;
    file.open("C:/Users/DELL/Desktop/CP/Compiler/file.txt");
    string str;
    getline(cin,str);
    file<<str<<"\n";
    file.close();



    FILE *fp;
    fp=fopen("file.txt","w+");
    ifstream input("file.txt");
    string ch;
    while(getline(input, ch, ' '))
    {
        if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
                ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
                ch == '[' || ch == ']' || ch == '{' || ch == '}')
        {

            fputs(ch," is a Delimiter");
        }
        else if(ch == '+' || ch == '-' || ch == '*' ||
                ch == '/' || ch == '>' || ch == '<' ||
                ch == '=')
        {
            fputs(ch," is a Delimiter");
        }
        else if(ch == '0' || ch == '1' || ch == '2' ||
                ch == '3' || ch == '4' || ch == '5' ||
                ch == '6' || ch == '7' || ch == '8' || ch == '9')
        {
            fputs(ch," is a Delimiter");
        }
        else if(ch == 'if' || ch == 'else' || ch == 'while' ||
                ch == 'double' || ch == 'float' || ch == '5' ||
                ch == '6' || ch == '7' || ch == '8' || ch == '9')
        }
    fclose(fp);
    return 0;




}

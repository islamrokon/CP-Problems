#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp;
    char ch;
    char str[100];
    int v=0,c=0;
    fp=fopen ("filed.txt","r");
    if(fp==NULL)
    {
        cout<<"There is no text";
        exit(-1);

    }
    while(!feof(fp)){
        fgets(str,100,fp);
        cout<<str;
    }
    cout<<"\n";
    fseek(fp,0,SEEK_SET);
    while(ch!=EOF)
    {
        ch=fgetc(fp);
        if((ch=='a') || (ch=='A') ||(ch=='e') ||(ch=='E') ||(ch=='i') ||(ch=='I') ||(ch=='o') ||(ch=='O') ||(ch=='u') ||(ch=='U'))
        {
            v++;
            cout<<"("<<ch<<")";
        }
        else if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))

        {
            c++;
            cout<<ch;
        }
    }
    fclose(fp);
    cout<<"\n";
    cout<<"Number of vowels are:"<<v<<"\n"<<"Number of consonants are:"<<c;
    return 0;
}

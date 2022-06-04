#include<bits/stdc++.h>
using namespace std;
int main()
{

    FILE *fp;
    fp=fopen("filed.txt","w+");
    fputs("This is tutorilspoint.com",fp);
    fseek(fp,7,SEEK_SET);
    fputs(" C Programming",fp);
    fclose(fp);
    return 0;
}

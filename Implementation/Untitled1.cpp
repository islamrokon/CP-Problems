#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>




bool isDelimiter(char ch)
{
    if(ch==' ' || ch== '+' || ch=='-' || ch=='*'
            || ch== '/' || ch== ',' || ch== ';' || ch== '<'
            || ch== '>' || ch== '=' || ch== '(' || ch== ')'
            || ch== '{' || ch== '}' || ch== '[' || ch== ']' )



        return (true);
    return (false);
}




bool isOperator(char ch)
{



    if( ch== '+' || ch== '-' || ch== '*' || ch== '/'
            || ch== '%' || ch== '<' || ch== '>' || ch== '=')



        return (true);
    return (false);



}



bool validIdentifier(char* str)
{



    if(str[0] =='0' || str[0]== '1' || str[0]== '2'
            || str[0]== '3' || str[0]== '4' || str[0]== '5'
            || str[0]== '6' || str[0]== '7' || str[0]== '8'
            || str[0]== '9' || isDelimiter(str[0])==true)



        return (false);
    return(true);
}




bool isKeyword(char* str)
{
    if(!strcmp(str,"if") || !strcmp(str,"else") || !strcmp(str,"while")
            || !strcmp(str,"do") || !strcmp(str,"case") || !strcmp(str,"break")
            || !strcmp(str,"continue") || !strcmp(str,"int") || !strcmp(str,"char")
            || !strcmp(str,"double") || !strcmp(str,"float") || !strcmp(str,"return")
            || !strcmp(str,"sizeof") || !strcmp(str,"long") || !strcmp(str,"short")
            || !strcmp(str,"typedef") || !strcmp(str,"switch") || !strcmp(str,"unsigned")
            || !strcmp(str,"goto") || !strcmp(str,"struct") || !strcmp(str,"void"))
        return (true);
    return (false);



}




char* subString(char* str, int left,int right)
{
    int i;
    char* subStr=(char*)malloc(sizeof(char) * (right -left +2));



    for(i=left; i<=right; i++)
        subStr[i-left]=str[i];
    subStr[right -left +1]='\0';
    return(subStr);
}



void parse(char* str)  //int a =b+c
{
    int left = 0, right = 0;
    int length = strlen(str);
    printf("- -Answer - -\n");
    while (right <= length && left <= right)
    {

        if (isDelimiter(str[right]) == false)
            right++;
        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
                printf("'%c' is a Valid Operator \n", str[right]);
            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right || (right == length && left != right))
        {
            char* subStr = subString(str, left, right - 1);
            if (isKeyword(subStr) == true)
                printf("'%s' is a Valid Keyword \n", subStr);
            else if ( validIdentifier(subStr) == true
                      && isDelimiter(str[right - 1]) == false)
                printf("'%s' is a Valid Identifier \n", subStr);
            else if ( validIdentifier(subStr) == false
                      && isDelimiter(str[right - 1]) == false)
                printf(" '%s' is a Invalid Identifier \n", subStr);
            left = right;
        }
    }
    return;
}




int main()
{
    char str[100];
    printf("Please Enter the line : \n");
    gets(str);



    parse(str);
    return (0);
}

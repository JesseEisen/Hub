/**
Q1: 编写函数itob(n,s,b),将整数n转换成以b为底的数，并将转换结果以字符的形式保存到字符串s中，例如，itob(n,s,16),将整数n格式化成十六进制的整数保存在s中

Q2：修改itoa函数，使得该函数可以接受三个参数，其中，第三个参数为最小字符宽度。为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得结果的左边填充一定的空格

**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN  200

//reverse the number
void reverse(char s[], int len)
{
    int  i,j=len-1;
    char temp;

    for(i = 0; i< len/2; i++){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
}


void myitob(int n, char s[], int b)
{

    int i = 0;
    while(n != 0){
        s[i] = n%b + '0';
        n = n/b;
        i++;
    }
    s[i] = '\0';
    reverse(s, i);
}


void myitoa(int n, char s[], int width)
{
    int i = 0;
    while(n != 0){
        s[i] = n%10 + '0';
        n = n/10;
        i++;
    }
    //if not meet the least width,add some blank spaces
    if(i < width){
        while(i < width){
            s[i] = ' ';
            i++;
        }
    }
    s[i] = '\0';
    reverse(s,i);
}

int main(int argc, char const *argv[])
{
    char s[MAXLEN] = {0};

    //myitob(24,s,2);
    myitoa(24,s,6);
    //printf("24 convert to binary is %s\n",s);  //result: 11000
    printf("24 convert to string is |%s|\n",s);  //result: |    24|

    return 0;
}

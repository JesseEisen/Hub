/**
Q1: 编写函数strrindex(s,t), 它返回字符串t在s中最右边出现的位置，如果s中不包含t，则返回-1

Q2：编写函数strend(s,t), 如果字符串t出现在字符串s的尾部，则返回1，否则返回0
**/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int strend(const char *s, const char *t)
{
    int diff = 1;
    size_t l1, l2;

    l2 = strlen(t);
    if(!l2)
        return -1;
    l1 = strlen(s);
    while(l1 >= l2)
    {
        l1--;
        if(!memcmp(s,t,l2))
            diff = l1 - l2;
        s++;
    }

    if(diff == -1)
        return 1;
    else
        return 0;
}


/*
    return the mostright index
 */
int strrindex(const char *s, const char *t)
{
    int index,temp;
    size_t l1, l2;


    l2 = strlen(t);
    if(!l2)
        return -1;
    l1 = strlen(s);
    index = l1;
    while(l1 >= l2)
    {
        l1--;
        if(!memcmp(s,t,l2))
            temp = l1;
        s++;
    }

    return (index-temp);

}


int main(int argc, char const *argv[])
{
    char *s1 = "helloworld";
    char *s2 = "ld";
    char *s3 = "or";

    printf("the mostright index is %d\n",strrindex(s1,s2));
    printf("%s is the end? %d\n",s2,strend(s1,s2));
    printf("%s is the end? %d\n",s3,strend(s1,s3));
    return 0;
}

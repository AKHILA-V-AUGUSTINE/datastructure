#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int len,i,str1[10],str2[10],str3[20],c;
printf("Enter the length of strings:");
scanf("%d",&len);
printf("Enter the first string elements:\n");
for(i=0;i<len;i++)
{
scanf("%d\n",&c);
if(c<0||c>1)
{
printf("plz enter the binary values");
}
else
{
str1[i]=c;
}
}
printf("Enter the second string elements");
for(i=0;i<len;i++)
{
scanf("%d\n",&c);
if(c<0||c>1)
{
printf("Enter the valid binary values");
}
else
str2[i]=c;
}
printf(" the union set is:\n");
for(i=0;i<len;i++)
{
if(str1[i]||str2[i]==1)
{
printf("1");
}
else
{
printf("0");
}
printf("the intersection set is\n");
for(i=0;i<len;i++)
{
    printf(str1[i]*str2[i]);
}
printf("\n the set difference of above 2 sets are:\n");
for(i=0;i<len;i++)
{
    str3[i]=!(str2[i]);
    str3[i]=str1[i]||str3[i];
    printf("%d",str3[i]);
}
}
}


#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[20],b[20],c[40],n,m,i,j,temp;

    printf("Enter the size of1array");
    scanf("%d",&n);
    printf("Enter the elements of 1 arrays");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the size of 2nd array");
    scanf("%d",&m);
    printf("Enter the elements in 2 array\n");
    for(i=0;i<m;i++)
    scanf("%d",&b[i]);
    printf("1 array contain elements are:\n");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
    printf("2 array contain elements are:\n");
    for(i=0;i<m;i++)
    printf("%d\n",b[i]);
    for(i=0;i<n;i++)
        c[i]=a[i];
    for(i=n;i<m+n;i++)
        c[i]=b[i-n];
    printf("Elements in third array is");
    for(i=0;i<m+n;i++)
        printf("%d\n",c[i]);

    for(j=0;j<m+n;j++)
        if(c[j]>c[j+1])
        {
        temp=c[j];
    c[j]=c[j+1];
    c[j+1]=temp;
        }
        printf("The sorted array is:\n");
        for(i=0;i<m+n;i++)
            printf("%d\n",c[i]);

    }

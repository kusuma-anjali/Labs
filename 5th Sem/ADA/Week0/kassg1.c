#include<stdio.h>

int main()

{
    int i=0,n,max,a[50];
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("the max element is %d \n",max);
    return 0;

}

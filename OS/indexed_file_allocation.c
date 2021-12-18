#include<stdio.h>
#include<stdlib.h>
int main()
{
    int index[50],f[50]={0},i,j,n,p,c;
    x:
    printf("\nEnter index block:");
    scanf("%d",&n);
    if(f[n]==0)
    {
        f[n]=1;
        printf("\nEnter the number of files on index.");
        scanf("%d",&p);
    }
    else{
    printf("\nBlock already allocated.");
    goto x;
    }
    printf("\nEnter the file numbers to be allocated:");
    for(i=0;i<p;i++)
    scanf("%d",&index[i]);
    for(i=0;i<p;i++)
    if(f[index[i]]==1)
    {
        printf("\nBlock already allocated.");
        goto x;
    }
    
    for(j=0;j<n;j++)
    f[index[j]]=1;
    printf("\nAllocated.");
    printf("\nFile indexed.");
    for(int k=0;k<p;k++)
    printf("\n%d->%d:%d",n,index[k],f[index[k]]);
    printf("\n1 to add file 0 to exit.");
    scanf("%d",&c);
    if(c==1)
    goto x;
    else
    exit(0);
    return 0;
}

/*Sum of subsets */
#include<stdio.h>

int w[10],d,n,count,x[10],i;

void sum_of_subsets(int s, int k, int r)
{
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("\n Subset %d = ", ++count);
        for(i=0;i<=k;i++)
            if(x[i])
                printf(" %d " , w[i]);

    }
    else if (s+w[k]+w[k+1] <=d)
        sum_of_subsets(s+w[k],k+1,r-w[k]);

    if( (s+r-w[k] >=d) && ((s+w[k+1]) <= d))
    {
        x[k]=0;
        sum_of_subsets(s,k+1,r-w[k]);
    }
}

void main()
{
    int sum=0,k;
    printf("\n Enter the no of elements");
    scanf("%d" , &n);

    printf("\n Enter the elements in ascending order ");
    for(i=0;i<n;i++)
        scanf("%d" , &w[i]);
    
    printf("\n Enter the sum");
    scanf("%d", &d);

    for(i=0;i<n;i++)
        x[i]=0;
    for(i=0;i<n;i++)
        sum=sum+w[i];

    if(sum<d || w[0]>d)
        printf("\n No subset possible");
    else
        sum_of_subsets(0,0,sum);

}


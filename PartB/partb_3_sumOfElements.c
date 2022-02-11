
/**Sum of elements **/ 

#include<stdio.h>
#include<conio.h>

int a[20],n,i,sum;
int findSum(int a[], int n)
{
    if (n <= 0)
        return 0;
    return (findSum(a, n - 1) + a[n - 1]);
}
 

void main()
{
    printf("\nEnter the number of elements: \n");
    scanf("%d", &n );
    printf("\nEnter the element of the array : \n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i] );
       
    }
    printf("\n");
     for(i=0;i<n;i++)
        printf(" %d , " , a[i]);
    
    printf("\n");
        
    sum= findSum(a,n);
    
     printf("\nSum of elements =  %d \n" , sum );
    
}
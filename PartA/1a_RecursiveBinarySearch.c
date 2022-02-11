#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int RBinarySearch( int a[] , int key, int n, int first, int last)
{
    int mid,i,j,temp;
    if(last<first)
        return -1;


   
mid=(first+last)/2;

if(key==a[mid])
    return mid;
else if(key<a[mid])
    return RBinarySearch(a,key,n,first,mid-1);
else    
    return RBinarySearch(a,key, n,mid+1, last);
}

void main()
{
    char ch;
    int a[100],n,key,i,res=-1,first,last,j,temp;
    clock_t st,et;
	double time_taken;
    printf("Enter the number of elements in the array : \n");
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter the key element to search: \n");
    scanf("%d",&key);
    first=0;
    last=n-1;
 
  //Sort array
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-2-i;j++)
        {
            if(a[j+1] < a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
    printf("sorted array is :");
    for(i=0;i<=n-1;i++)
        printf(" %d",a[i]);

 
    st=clock(); // record start time
    res=RBinarySearch(a,key,n,first,last);
    et=clock(); // record end time
    time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;
    
    if(res==-1)
            printf("\nThe search element is not found\n");
    else    
        printf("\nThe search element is found at position %d\n",res+1);

    printf("The ExecutionTime is = %f Of Milli Seconds", time_taken);
}
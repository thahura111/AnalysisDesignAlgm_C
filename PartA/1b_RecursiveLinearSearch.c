#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int RLinearSearch( int a[] , int key, int n, int first, int last)
{
    int mid,i,j,temp;
    if(last<first)
        return -1;

 

if(key==a[first])
    return first;
else if(first< last) 
    RLinearSearch(a,key,n,first+1,last);
else 
    return -1; 
}

void main()
{
    char ch;
    int a[100],n,key,i,res=-1,first,last;
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
 
 
    st=clock(); // record start time
    res=RLinearSearch(a,key,n,first,last);
    et=clock(); // record end time
    time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;
    
    if(res==-1)
            printf("\nThe search element is not found\n");
    else    
        printf("\nThe search element is found at position %d\n",res+1);

    printf("The ExecutionTime is = %f Of Milli Seconds", time_taken);
}
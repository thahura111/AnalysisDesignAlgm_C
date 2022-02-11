#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int partition( int a[], int low, int high)
{
   
    int pivot , j, temp,i;
    pivot=low; 
    i=low;
    j=high;

    while(i<j)
    {

        while( i<high && a[i]<=a[pivot]) 
        {
            i++;
        }

        while( j>low && a[j]>a[pivot]) 
        {
            j--;
        }

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    
    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    return j;
}

int quickSort( int a[] , int low, int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
    }
        
}


void main()
{
    int a[100],n,first,last,i;
    clock_t st,et;
	double time_taken;
    printf("Enter the number of elements in the array : \n");
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Elements of array before quicksort :");
    for(i=0;i<=n-1;i++)
        printf(" %d",a[i]);

     printf("\n");
    first=0;
    last=n-1;
    

    st=clock(); // record start time
    quickSort(a,first, last);
    et=clock(); // record end time
    time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;
    
    printf("Elements of array after quicksort :");
    for(i=0;i<=n-1;i++)
        printf(" %d",a[i]);

    printf("\n");
    printf("The ExecutionTime is = %f Of Milli Seconds", time_taken);
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

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
    int a[100],sortedA[100],n,key,i,res=-1,first,last,j,temp,choice;
    clock_t st,et;
    double time_taken;
    printf("Enter the number of elements in the array : \n");
    scanf("%d",&n);
	
	first=0;
    last=n-1;
		
    printf("Enter the elements in the array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter 1 for Binary search, 2 for Linear search, 3 to exit: \n");
    scanf("%d",&choice);
	
	while(choice!=3){
	    printf("Enter the key element to search: \n");
        scanf("%d",&key);
        
    	if(choice==1){
    	    //copy the array to sortedA
    	    memcpy(sortedA, a, sizeof(a));
    		//Sort array
    		for(i=0;i<=n-2;i++)
    		{
    			for(j=0;j<=n-2-i;j++)
    			{
    				if(sortedA[j+1] < sortedA[j])
    				{
    					temp=sortedA[j];
    					sortedA[j]=sortedA[j+1];
    					sortedA[j+1]=temp;
    				}
    			}
    		}
    		
    		printf("\nsorted array is :");
    		for(i=0;i<=n-1;i++)
    			printf(" %d",sortedA[i]);
    
			printf("\n"):
    		st=clock(); // record start time
    		res=RBinarySearch(sortedA,key,n,first,last);
    		et=clock(); // record end time
    		time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;
    		
    	}else{
			printf("\nArray is :");
    		for(i=0;i<=n-1;i++)
    			printf(" %d",a[i]);
			
			printf("\n"):
    		st=clock(); // record start time
    		res=RLinearSearch(a,key,n,first,last);
    		et=clock(); // record end time
    		time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;
    	}
    	
    	
        
        
        if(res==-1)
                printf("\n\nThe search element is not found\n");
        else if (choice==1)   
                printf("\n\nThe search element is found at position %d in sorted array",res+1);
        else
            printf("\nThe search element is found at position %d in the array\n",res+1);
    
        printf("The ExecutionTime is = %f Of Milli Seconds", time_taken);
        
        printf("\n\n\nEnter 1 for Binary search, 2 for Linear search, 3 to exit: \n");
        scanf("%d",&choice);
	}
}
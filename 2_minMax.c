#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void minMAx( int a[] ,int n )
{
    int min, max , i; 
    //initialize
    min=max=a[0]; 
    
    for(i=0;i<=n-1;i++){
        //compare min
		if(a[i]<min)
			min=a[i];
				
		//compare max
		if(a[i]>max)
			max=a[i];		
    }

    printf("Minimum element = %d \n", min);
    printf("Maximum element = %d \n", max);
   
}

void main()
{
    char ch;
    int a[100],n,i,res[2],first,last;
    clock_t st,et;
	double time_taken;
    printf("Enter the number of elements in the array : \n");
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    
    st=clock(); // record start time
    minMAx(a,n);
    et=clock(); // record end time
    time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;   

    printf("The ExecutionTime is = %f Of Milli Seconds", time_taken);
}
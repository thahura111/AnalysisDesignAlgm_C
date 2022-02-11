
/**Fibonacci series till a given number **/ 

#include<stdio.h>
#include<conio.h>

int n,i;


int fibonacci(int i){ 
	if(i==0) return 0; 
	else if(i==1) return 1; 
	else return (fibonacci(i-1)+fibonacci(i-2));
} 


void main()
{
    int f=0;
    printf("\nEnter the element to find the fibonacci series : \n");
    scanf("%d", &n );
    printf("\nFibonacci of %d elements is : \n" , n );
   printf("fibonacci series is : \n");
	for(i=0;i<n;i++) { 
		printf("%d ",fibonacci(i));
	}
    
    
}
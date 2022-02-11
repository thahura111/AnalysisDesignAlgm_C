
/**Factorial of number **/ 

#include<stdio.h>
#include<conio.h>

int n;


int  fact(int n )
{
    if (n==0)
        return 1;
    else
        return n*fact(n-1);
}


void main()
{
    int f=0;
    printf("\nEnter the element to find the factorial : \n");
    scanf("%d", &n );
    f = fact(n);
    printf("\nFactorial of %d is %d \n" , n , f);
    
    
}

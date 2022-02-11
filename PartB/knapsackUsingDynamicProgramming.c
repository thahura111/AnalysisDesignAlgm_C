
/** 0/1 Knapack **/ 

#include<stdio.h>
#include<conio.h>

int i,j,n,capacity, w[50],p[50],maxprofit;
int maximum (int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

 int knapsack( int i, int c)
{
     
    if(i==n){
        return ( (c < w[n])? p[n] : 0 ); 
    }
    
    if( c<w[i]){
        
        return knapsack ( i+1, c);
    }
        return  maximum ( knapsack(i+1, c) , knapsack(i+1, c-w[i]) + p[i]);
}


void main()
{
    
/*   printf("\n Enter no of objects : \n");
    scanf("%d", &n );

    printf("Enter the weights\n");
    for(i=0;i<n;i++)
        scanf("%d" , &w[i]);

    printf("\n Enter the profits associated \n");
    for(i=0;i<n;i++)
        scanf("%d" , &p[i]);
    
    printf("\n Enter the capacity \n");
        scanf("%d" , &capacity);*/

n=5;
w[0] = 100 ;
w[1] = 14 ;
w[2] = 10 ;


p[0] = 20 ;
p[1] = 18 ;
p[2]= 15 ;

capacity =116 ;


    maxprofit = knapsack(0, capacity);
    printf("\n Maximum profit = %d" , maxprofit);
}

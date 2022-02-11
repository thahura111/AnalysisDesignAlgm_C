
/** fractional Knapack **/ 

#include<stdio.h>
#include<conio.h>

int i,j,n,M , capacity, w[50],p[50],s[10],maxprofit , maxIndex;

float  maxRatio =0, remainingCapacity,fraction,totalProfit=0.0; 

 void knapsack( )
{
   
     
   for(i=0;i<n;i++)
   {
    s[i]=0; //initialzie -  ith element is not selected
    printf("\n Element %d : w[%d] = %d , p[%d]=%d , ratio of profit/weight = %f" ,i+1,i,  w[i] ,i, p[i] , (double)p[i]/w[i] );
   }
    
    printf("\n M = %d \n", M );
   remainingCapacity=M;
    
    //fill the knapsack with maximum ratio of profit/weights
    
    for(j=0; j<n  ;j++ ) 
    {
        
        maxRatio = -1 ;
        maxIndex = -1; 
        
        
       
        for(i=0;i<n  ; i++) 
        {
            if (s[i]==0) {
                if(maxRatio<(double) p[i]/w[i]){
                    maxRatio = (double) p[i]/w[i] ;   
                    maxIndex= i;
                }
            }
            
        }
        
        // printf("\n maxRatio = %f , maxIndex = %d , weight = %d ,profit = %d " , maxRatio, maxIndex , w[maxIndex] , p[maxIndex]); 
            
            
        //check the max ratio element to see if it can be added to knapsack 
        
        //check if whole can be added
        if (remainingCapacity-w[maxIndex] >=0) {
            remainingCapacity = remainingCapacity - w[maxIndex] ; 
            s[maxIndex] = 1; // maxIndex element is selected. 
            printf("\n Adding the element %d  to knapsack, ( %d weight  , %d profit ) , remainingCapacity = %f " , 
            maxIndex+1 , w[maxIndex] , p[maxIndex] , remainingCapacity );
            
            totalProfit =totalProfit + p[maxIndex] ;
            
        }
        else {
            printf("\n\n RemainingCapacity is not sufficiet to add other elements as whole, adding fractional part to knapsack\n" );
            
            fraction = remainingCapacity/w[maxIndex] ;            
           printf("\n Adding %f th of element %d to knapsack , ( %f weight  , %f profit ) , remainingCapacity = %f" , 
            maxIndex+1*fraction ,maxIndex+1,  w[maxIndex]*fraction , p[maxIndex] *fraction , (float)remainingCapacity-w[maxIndex]*fraction );         
            
            totalProfit = totalProfit +  p[maxIndex] *fraction ;
            break;
        }
    }
    
    printf("\n\n Total profit in knapsack is : %f" , totalProfit);
   
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
        scanf("%d" , &M);*/

n=5;
w[0] = 100 ;
w[1] = 14 ;
w[2] = 10 ;
w[3] = 20 ;
w[4]=200;


p[0] = 20 ;
p[1] = 18 ;
p[2]= 15 ;
p[3]= 25 ;
p[4]=20;

M =116 ;


    knapsack();
    
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int s[50][50];

void display( int x[] , int n)
{
    register int i,j;
    for(i=1;i<=n;i++)
    {
        //update the queen position in 2D array as 1
        // row = queen = i 
        // column = position of queen = x[i]
        s[i][x[i]]=1; 
    }

    for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(s[i][j])
                    printf(" Q ");
                else    
                    printf(" x ");
               
            }
             printf("\n");
        }

        exit(0);
}

int place(int x[], int queen , int position)
{
    int i;
    for(i=1;i<queen;i++)
    {
        //check if any other previous queen is in same row  
        if(x[i] == position)
            return 0; 
        //Check if any other queen in same diagonal 
        //(a,b) (c,d)  checl if abs(a-c) = abs(b-d)
        //k=rows, x[k]=columns
        // current queen position = (queen,position) =(a,b)
        //previous queen's position eg : (i,x[i]) = (c,d)
        //abs(a-c) == abs(b-d) ie, abs(queen-i) == abs(position-x[i])
        if( abs(queen-i) == abs(position-x[i]))
            return 0;
    }
    return 1;
}

void main()
{
    int x[25],n,k;
    printf("\n Enter the no of queens : ");
    scanf("%d" , &n);

    printf("\n The solution to queens problem is \n");
    //n--;
   /*
    * x array holds the positions for queens 
    eg:  x[1] = 2 ,means queen 1 can take column 3 , ie, (row 1, column 3)
     k = index used for x,  x[k]  , so k = 1,2,3,4 (in 4 queens problem)
     x[k] can take values 1,2,3,4 (column number) ;
     if queen2 (k=2) cannot be placed in any of 4 positions, ie , x[2]>4 , then backtack to previous queen
     i, backtrack to x[1] , ie k-1 ie, k=1 , queen1
     backtracking is possible from queen4 to queen 3 t queen 2 to queen
     ie, k>=1
   */
    for(x[1]=1,k=1; k>=1; x[k]+=1)
    {
        
        // step1 : check if queen k can be placed in any of 1 to n positions, eg x[2] =1,2,3,4 ? 
        while(x[k]<=n && !place(x, k ,x[k])){
            x[k]+=1;  // ie, try column 1, 2, 3, 4
        }

        // step 2: if queen k was placed within column 1,2,3,4 ie, <=n ,  then check the positions for other queen. 
        if(x[k]<=n) {
            
            if(k==n){
                //If queen n is reached, then finish the program by displaying. 
                display(x,n);
            }
            else{
                //Check the positions for other queen
                k++;
                x[k]=0; //initialize the next queen's position to 0
            }
        }
        else{
             // step 3: if queen k could not be placed within column 1,2,3,4.
             //Hence need to backtrack to previous queen k-- 
             // continue to check the new position for previous queen =>ie, continue the for loop
             k--;
        }
    }
    
     if(k==0)
    	printf("\nThere is no solution to  %d queen problem " , n );
    getch();
}
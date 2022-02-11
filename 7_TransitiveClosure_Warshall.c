/* All pair shortest path - Floyds */

#include<stdio.h>

int c[5][5],n,i,j,k,checkAllOnes;

void Warshall()
{
	//k = intermediate vertex
    for(k=1;k<=n;k++){
		//i = starting vertex
        for(i=1;i<=n;i++)
			//j= ending vertex
            for(j=1;j<=n;j++){
				//Transitive closure check : if path exists via intermediate vertex ie, c[i][k] and c[k][j] , then mark //c[i][j]=1
				//else,check if there is a direct path or not,ie, c[i][j]
				
				if(c[i][j] ==(1 || 0))
				    c[i][j] =  c[i][j] ;//|| (c[i][k] && c[k][j]);
				else if (c[i][k]==1 && c[k][j]==1){
				    c[i][j]=1;
				}
			
				
               /* if( (c[i][k] + c[k][j]) < c[i][j] )
                    c[i][j] = c[i][k] +c[k][j] ;
				*/
			}
			
		printf("\n After %d  iteration of k : \n" ,k); 
	     for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("%6d" , c[i][j]) ;
            }
            printf("\n"); 
        }
        
        printf("\n"); 
			
    }
                
}

void main()
{
    printf("\n Enter the number of vertices : ");
    scanf("%d" , &n );

    printf("\n Enter the adjacency matrix : \n");
    
    /*
    eg : Transitive
    1 1 0 0
    1 0 1 0
    1 1 0 0
    0 1 0 1
    
    eg : non Transitive
    1 0 1 
    0 0 1 
    0 1 0  
    */
    for ( i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            {
                scanf("%d", &c[i][j]) ;
                if( c[i][j] == 0 && i!=j)
                    c[i][j] = 999; 
            }
    
    Warshall();

    /*for(i=1;i<=n; i++ ){
        c[i][i] = 0;
    }*/

        printf("\n Matrix after applying Warshall' algorithm is : \n");
       
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(c[i][j]==999)
                    c[i][j]=0;
                printf("%6d" , c[i][j]) ;
            }
            printf("\n"); 
        }
       
        
}
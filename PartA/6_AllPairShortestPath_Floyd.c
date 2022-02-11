/* All pair shortest path - Floyds */

#include<stdio.h>

int c[5][5],n,i,j,k;

void floyd()
{
	//k = intermediate vertex
    for(k=1;k<=n;k++)
		//i = starting vertex
        for(i=1;i<=n;i++)
			//j= ending vertex
            for(j=1;j<=n;j++){
				//Check if path via intermediate vertex is shorter, pick that, ie, c[i][k]+c[k][j]
				//else pick the direct path , ie, c[i][j]
                if( (c[i][k] + c[k][j]) < c[i][j] )
                    c[i][j] = c[i][k] +c[k][j] ;
			}
}

void main()
{
    printf("\n Enter the number of vertices : ");
    scanf("%d" , &n );

    printf("\n Enter the adjacency matrix : \n");
    for ( i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            {
                scanf("%d", &c[i][j]) ;
                if( c[i][j] == 0 )
                    c[i][j] = 999; 
            }
    
    floyd();

    for(i=1;i<=n; i++ )
        c[i][i] = 0;

        printf("\n All pair shortest path is : \n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%6d" , c[i][j]) ;
            printf("\n"); 
        }
        
}
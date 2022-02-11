/*Minimum cost spanning tree using prims algorithm */
#include<stdio.h>

int a,b,u,v,n,i,j,no_of_edges=1;
int visited[10], min, mincost=0,cost[10][10];

void main()
{
/*
    printf("Enter the number of vertices");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix");


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d" , &cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

*/

//---------- hardcode values for easy testing ----------
n=4;
cost[1][1] = 999; //arry index starts with 1
cost[1][2] = 2;
cost[1][3] = 9;
cost[1][4] = 1;

cost[2][1] = 2;
cost[2][2] = 5;
cost[2][3] = 1;
cost[2][4] = 11;

cost[3][1] = 7;
cost[3][2] = 4;
cost[3][3] = 1;
cost[3][4] = 22;

cost[4][1] = 11;
cost[4][2] = 4;
cost[4][3] = 7;
cost[4][4] = 2;

printf("\nNumber of vertices = %d" , 4);
printf("\nAdjacency matrix = ") ;
 for(i=1;i<=n;i++)
 {
    printf("\n");    
     for(j=1;j<=n;j++)
    {
        printf(" %6d" , cost[i][j]);
    }       
}
printf("\n");  
//----------end of hardcode values for easy testing ----------


    //initalize source as 1st vertex
        visited[1]=1;
    //initalize other than 1st/source vertex as visited=0
    for(i=2;i<=n;i++)
        visited[i]=0;

    while( no_of_edges<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            
            for(j=1;j<=n;j++)
            {

                if(cost[i][j]<min) //find the minimum edge from visited (i) to unvisited (j)
                {
                    if(visited[i]==0) //Need only visited i , hence skipping others
                    {
                        continue;
                    }
                    else{ // visited vertex
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        
        if(visited[u]==0 || visited[v]==0) //selected edge's one vertex should be new/unvisited
        {
            //selected edge details 
            printf("\nEdge : (%d,%d) = %d" , a , b, min);
            visited[b]=1;
            no_of_edges++;
            mincost=mincost+min; //overall cost
        }
    cost[a][b]=cost[b][a]=999; //ignore this edge for next iterations as its already selected
    
    }

    printf("\nThe minimum cost of spanning tree is %d\n" , mincost);


}


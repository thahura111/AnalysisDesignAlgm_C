#include<stdio.h>
#include<conio.h>

void dijkstra(int G[10][10],int n,int startnode);
 
int main()
{
    int G[10][10],i,j,n,u;
    
    
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
            
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    
    
    /*
    //---------- hardcode values for easy testing ----------
    n=5;
    u=1;
    G[1][1] = 999; //arry index starts with 1
    G[1][2] = 1;
    G[1][3] = 999;
    G[1][4] = 3;
    G[1][5] = 10;
    
    G[2][1] = 999;
    G[2][2] = 0;
    G[2][3] = 5;
    G[2][4] = 999;
    G[2][5] = 999;
    
    G[3][1] = 999;
    G[3][2] = 999;
    G[3][3] = 0;
    G[3][4] = 999;
    G[3][5] = 1;
    
    G[4][1] = 999;
    G[4][2] = 999;
    G[4][3] = 2;
    G[4][4] = 999;
    G[4][5] = 6;
    
    G[5][1] = 999;
    G[5][2] = 999;
    G[5][3] = 999;
    G[5][4] = 999;
    G[5][5] = 0;
    
    printf("\nNumber of vertices = %d" , 5);
    printf("\nAdjacency matrix = ") ;
     for(i=1;i<=n;i++)
     {
        printf("\n");    
         for(j=1;j<=n;j++)
        {
            printf(" %6d" , G[i][j]);
        }       
    }
    printf("\n");  
    printf("\nStarting vertex = %d" , 1);
    printf("\n");  
    //----------end of hardcode values for easy testing ----------
    */

    dijkstra(G,n,u);
    return 0;
}
 
void dijkstra(int G[10][10],int n,int startnode)
{
 
    int cost[10][10],distance[10],pred[10];
    int visited[10],count,minDistance,nextnode,i,j;
    
    //pred[] stores the predecessor of each node 
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(G[i][j]==0)
                cost[i][j]=9999;
            else
                cost[i][j]=G[i][j];
        
        
    //initialize pred[],distance[] and visited[]
    for(i=1;i<=n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
        
        
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<=n-1)
    {
        minDistance=9999;
        //nextnode or "W" (in textbook) gives the node at minimum distance
        for(i=1;i<=n;i++)
        {
            if(distance[i]<minDistance&&!visited[i])
            {
                minDistance=distance[i];
                nextnode=i;
            }
        
        }
        //check if a better path exists through nextnode
        visited[nextnode]=1;
        for(i=1;i<=n;i++)
            if(!visited[i])
                if(minDistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=minDistance+cost[nextnode][i];
                    pred[i]=nextnode;//save the path
                }
                count++;
    }
         
    //print the path and distance of each node
    for(i=1;i<=n;i++)
        if(i!=startnode)
        {
            printf("\nDistance from starting vertex [%d] to [%d]=%d",startnode, i,distance[i]);
            printf("\tPath=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
        }
}
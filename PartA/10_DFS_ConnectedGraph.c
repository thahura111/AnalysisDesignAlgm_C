/* Check if graph is connected or not */
#include<stdio.h>
#include<conio.h>
int i,j,a[20][20],visited[20],n,label=0,k,I[10],v,w;

void initiate()
{
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        I[i]=0;
    }

    for (i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=0;
}

void dfs(int v)
{
    visited[v]=1;
    I[v]=label;
    for(i=1;i<=n;i++)
        if(a[v][i] && visited[i]==0) 
            dfs(i);
}

void component_label()
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(I[i]==0)
        {
            label++;
            for(k=1;k<=n;k++)
                visited[i]=0;
                dfs(i);
        }
    }
    if(label>1)
        printf("\n Disconnected graph");
    else    
        printf("\n Graph is connected");

    printf("\n No of connected elemens : %d ", label);
    for(i=1;i<n;i++)
        printf("\n Vertex %d belongs to component %d" , i , I[i]);
}

void main()
{
     
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    
    initiate();
    printf("\nEnter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
            
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    

   //---------- hardcode values for easy testing ----------
   /*
    n=5;
    initiate();
    a[1][1] = 999; //arry index starts with 1
    a[1][2] = 1;
    a[1][3] = 999;
    a[1][4] = 3;
    a[1][5] = 10;
    
    a[2][1] = 999;
    a[2][2] = 0;
    a[2][3] = 5;
    a[2][4] = 999;
    a[2][5] = 999;
    
    a[3][1] = 999;
    a[3][2] = 999;
    a[3][3] = 0;
    a[3][4] = 999;
    a[3][5] = 1;
    
    a[4][1] = 999;
    a[4][2] = 999;
    a[4][3] = 2;
    a[4][4] = 999;
    a[4][5] = 6;
    
    a[5][1] = 999;
    a[5][2] = 999;
    a[5][3] = 999;
    a[5][4] = 999;
    a[5][5] = 0;
    
    printf("\nNumber of vertices = %d" , 5);
    printf("\nAdjacency matrix = ") ;
     for(i=1;i<=n;i++)
     {
        printf("\n");    
         for(j=1;j<=n;j++)
        {
            printf(" %6d" , a[i][j]);
        }       
    }
    printf("\n");  
	*/
    //----------end of hardcode values for easy testing ----------

    component_label();
    getch();

}
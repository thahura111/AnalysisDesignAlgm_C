
/** DFS **/ 

#include<stdio.h>
#include<conio.h>
int s[10]={0};

int q[10],f=-1, r=-1;

void dfs(int n , int a[10][10], int u)
{
    int v;
    s[u]=1;
    printf("%d ", u);
    for(v=1;v<=n;v++)
        if(a[u][v]==1 && s[v]==0)
            dfs(n,a,v);
}



void main()
{
    int a[10][10],n,src,i,j;

   printf("\n Enter no of vertices : \n");
    scanf("%d", &n );

    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d" , &a[i][j]);

    printf("\n Enter the source vertex \n");
    scanf("%d" , &src);

/*n=5;
a[1][1] = 0 ;
a[1][2] = 1 ;
a[1][3] = 0 ;
a[1][4] = 1 ;
a[1][5] = 0 ;

a[2][1] = 0 ;
a[2][2] = 0 ;
a[2][3] = 0 ;
a[2][4] = 1 ;
a[2][5] = 1 ;

a[3][1] = 1 ;
a[3][2] = 0 ;
a[3][3] = 0 ;
a[3][4] = 1 ;
a[3][5] = 0 ;

a[4][1] = 0 ;
a[4][2] = 0 ;
a[4][3] = 0 ;
a[4][4] = 0 ;
a[4][5] = 1 ;

a[5][1] = 0 ;
a[5][2] = 0 ;
a[5][3] = 0 ;
a[5][4] = 0 ;
a[5][5] = 0 ;

src =1 ;*/

    if(src<=n){
        dfs(n,a,src);
         printf(" \n The nodes that are reachable from %d are : \n", src);
         for(i=1;i<=n;i++)
            {
                if(s[i])
                    printf("%d     \n" , i);
             }
    }
    else
        printf("\n invalid source entered , try again\n");
}

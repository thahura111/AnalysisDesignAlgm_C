
/** BFS **/ 
#include<stdio.h>
#include<conio.h>
int q[10],f=-1, r=-1;

void qins(int x)
{
    if(f==-1 && r==-1)
    {
        f++;
        q[++r]=x;
    }else{
        q[++r]=x;
    }
}


int qdel()
{
    int x=q[f];
    
    if(f==r){
        f=r=-1;
    }
    else    {
        f++;
    }
        
    return x;
}

void main()
{
    int u,s[10]={0}, src,n,a[10][10],i,j;

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

    s[src]=1;

    qins(src);

    while(f!=-1 && r!=-1)
    {
        u=qdel();
        for(i=1;i<=n;i++)
            if(a[u][i]==1 && s[i]==0)
            {
                s[i]=1;
                qins(i);
            }

    }

    printf(" \n The nodes that are reachable from %d are : \n", src);
    for(i=1;i<=n;i++)
    {
        if(s[i])
            printf("%d     \n" , i);
    }
    getch();

}
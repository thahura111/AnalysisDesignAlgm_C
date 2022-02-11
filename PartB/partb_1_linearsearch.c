
/**Linear search **/ 

#include<stdio.h>
#include<conio.h>

int a[20],n,i,e, eleIndex;


int findEle(int a[], int n , int e)
{
     eleIndex=-1;
    for(i=0;i<n;i++){
        if(a[i]==e)
            eleIndex= i;
    }
    return eleIndex;
}
 

void main()
{
    printf("\nEnter the number of elements: \n");
    scanf("%d", &n );
    printf("\nEnter the element of the array : \n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i] );
       
    }
    printf("\nEnter the element to search : \n");
    scanf("%d", &e );
    
       printf("\n");
        
    eleIndex= findEle(a,n ,e);
    
    printf("\nElements in array are : \n" );
    for(i=0;i<n;i++){
        printf("%d  ,  ", a[i] );
       
    }
    printf("\n");
    if(eleIndex==-1)
        printf("\nElement not found\n"  );
    else
        printf("\nElement %d found at position : %d  \n" , e , eleIndex+1  );
    
}
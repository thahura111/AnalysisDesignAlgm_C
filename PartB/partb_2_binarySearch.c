
/**Binary search **/ 

#include<stdio.h>
#include<conio.h>

int a[20],n,i,j,eleIndex,mid,key;

void bubbleSort(int a[], int n) {

  // loop to access each array element
  for (int i = 0; i < n - 1; i++) {
      
    // loop to compare array elements
    for (j = 0; j < n-1-i; j++) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (a[j] > a[j + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

int binarySearch(int a[],int first, int last , int key)
{
     eleIndex=-1;
     
    while(first<=last) { 
        mid= (first+last) /2 ;
       
        if(key==a[mid]){
            eleIndex=mid;
             return eleIndex;
        }
        else if (key<a[mid])
            last=mid-1;
        else
            first=mid+1; 
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
    scanf("%d", &key);
    
       printf("\n");
        
   
    
    printf("\nElements in array are : \n" );
    for(i=0;i<n;i++){
        printf("%d  ,  ", a[i] );
       
    }
    printf("\n");
    
    bubbleSort(a,n);
    
    printf("\nElements after sorting are : \n" );
    for(i=0;i<n;i++){
        printf("%d  ,  ", a[i] );
       
    }
    printf("\n");
    
    
    eleIndex= binarySearch(a,0,n-1,key);
     
    if(eleIndex==-1)
        printf("\nElement not found\n"  );
    else
        printf("\nElement %d found at position : %d  \n" , key , eleIndex+1  );
    
}
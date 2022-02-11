// Bubble sort in C

#include <stdio.h>

int i, j,n,a[30];
// perform the bubble sort
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

// print array


int main() {
    printf("\n Enter no of elements : \n");
    scanf("%d", &n );

    printf("Enter the elements \n");
    for(i=0;i<n;i++)
        scanf("%d" , &a[i]);

  bubbleSort(a, n);
  
  printf("Sorted Array in Ascending Order:\n");
  for ( i = 0; i < n; ++i) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>



int Merge( int a[], int left, int mid, int right)
{
	// arr.length=5 ; left=0 ,right=4, mid=2
		// leftArray = 0,1,2,25555   size = 4 = mid-left +2
		// rightArray = 3,4,255555   size = 3  = right-mid + 1
		int leftArray [10];
		int rightArray [10];

		int i=0; //leftArray index
		int j=0; //right Array index
		int k=0; //index of a

		 i=0; //leftArray index
		 j=0; //right Array index
		 k=0; //index of a
		/*
		 * copy 1st half to left array
		 * 0,1,2   left .. mid
		 */
		for(k=left;k<=mid;k++) {
			leftArray[i]=a[k];
			i++;
		}
		//initalize last element of leftArray with MAX number
		leftArray[i]=999;

		/*
		 * copy 2nd half to right array
		 * 3,4   mid+1 .. right
		 */
		for(k=mid+1;k<=right;k++) {
			rightArray[j]=a[k];
			j++;
		}

		//intialize last element of rightArray with MAX number
		rightArray[j]=999;


		/* compare left and right array
		 * and place elements in correct order in arr
		 */

		i=0;
		j=0;
		for(k=left; k<=right;k++) {

			if(leftArray[i] < rightArray[j] ) {
				a[k] = leftArray[i];
				i++;
			}else {
				a[k]=rightArray[j];
				j++;
			}
		}
		return 0;

}

int mergeSort( int a[] , int low, int high)
{
    int mid;

    if(low<high)
    {
	mid=(low+high)/2;
	mergeSort(a,low,mid);
	mergeSort(a,mid+1,high);
	Merge(a,low,mid,high);
    }
      return 0;
}


void main()
{
    int a[100],n,first,last,i;
    clock_t st,et;
	double time_taken;
    printf("Enter the number of elements in the array : \n");
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);

    printf("Elements of array before merge sort :");
    for(i=0;i<=n-1;i++)
	printf(" %d",a[i]);

     printf("\n");
    first=0;
    last=n-1;


    st=clock(); // record start time
	//running merge sort for 20k times to capture time
    for(i=0;i<20000; i++)
		mergeSort(a,first, last);
    et=clock(); // record end time
     time_taken= (((double)(et-st))/ CLOCKS_PER_SEC)*1000;

    printf("Elements of array after merge sort :");
    for(i=0;i<=n-1;i++)
	printf(" %d",a[i]);

    printf("\n");
   // printf("The ExecutionTime is = %f Of Milli Seconds", time_taken);
    time_taken = time_taken/20000;  //average it out by dividing by 20K
    printf("\n ** Average exe time in milli seconds = %f", time_taken);
    getch() ;
    clrscr();
}
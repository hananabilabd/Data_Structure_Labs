#include <stdio.h>
#include <stdlib.h>
// selection sort
void selection_sort(int arr[], int size){
    int i,temp,counter,min;
    for(counter =0 ;counter<size;counter++){
		min=counter;
		for (i=counter+1;i<size;i++){
		if (arr[min]>arr[i]){
				min=i;
				}
		}
		 temp = arr[counter];
		 arr[counter]=arr[min];
		 arr[min]=temp;
	}
}
int main (void){

	int i;int i2;int temp,counter,size;
	printf("-----------Selection Sort------------\n");
	printf("Enter array size=",size);
	scanf("%d",&size);
	int *arr =(int*)malloc(sizeof(int)*size);
	for( i=0;i<size;i++){
		printf("Enter Num %d=",i);
		scanf("%d",&arr[i]);

	}

	selection_sort(arr,size);

	// for printing the sorting array
	for( i2=0;i2<size;i2++){
		printf("array[%d]= %d \n",i2,arr[i2]);


	}



	return 0;
}

#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int arr[],int size){
	int i, temp,counter;
	for(counter =0 ;counter<size;counter++){
		temp= arr[counter];
		for (i=counter-1;i>=0 && arr[i]>temp;i--)
		{
			arr[i+1]=arr[i];
		}
	arr[i+1]=temp;
	}
}
int main (void){
	int i;int i2;int temp,counter,size;
	printf("-----------Insertion Sort------------\n");
	printf("Enter array size=");
	scanf("%d",&size);
	int *arr =(int*)malloc(sizeof(int)*size);

	//for inputing array
	for( i=0;i<size;i++){
		printf("Enter Num %d=",i);
		scanf("%d",&arr[i]);

	}
    insertion_sort(arr,size);

	// for printing the sorting array
	for( i2=0;i2<size;i2++){
		printf("array[%d]= %d \n",i2,arr[i2]);


	}



	return 0;
}

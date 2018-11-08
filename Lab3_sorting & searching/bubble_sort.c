#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr[],int size){
		int temp,counter,flag_sorted=0,i;
	for(counter =0 ;counter<size && flag_sorted==0;counter++){ //or ( l=5;l>0;l--)
		flag_sorted=1;
		for (i=0;i<size-counter-1;i++){//or ( i =0 ;i<l;i++)
		if (arr[i]>arr[i+1]){
				 temp = arr[i];
				 arr[i]=arr[i+1];
				 arr[i+1]=temp;
				 flag_sorted=0;
				}
		}
	}
	}
int main (void){

	int l;int i;int i2;int temp,counter,size;
	printf("-----------Bubble Sort------------\n");
	printf("Enter array size=");
	scanf("%d",&size);
	int *arr =(int*)malloc(sizeof(int)*size);
	for( i=0;i<size;i++){
		printf("Enter Num %d=",i);
		scanf("%d",&arr[i]);

	}
	bubble_sort(arr,size);
	for( i2=0;i2<size;i2++){
		printf("array[%d]= %d \n",i2,arr[i2]);
	}



	return 0;
}

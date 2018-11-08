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
int binary_search(int arr[],int size , int num){
	//bubble sort el awal
	bubble_sort (arr,size);
	int min , max,mid;
	min =0;
	max =size-1;

	while(min <=max){
		mid =(max+min)/2;
		if (arr[mid]==num){
			return mid;
		}
		else if (num <arr[mid]){
			max =mid-1;
		}
		else {
			min=mid+1;
		}
		}
	return -1;
}
int main (void){

	int i;int i2;int result,counter,search,size;
	printf("-----------Binary Search------------\n");
	printf("Enter array size=");
	scanf("%d",&size);
	int *arr =(int*)malloc(sizeof(int)*size);

	//for inputing array
	for( i=0;i<size;i++){
		printf("Enter Num %d=",i);
		scanf("%d",&arr[i]);

	}
	printf("Enter Num you wanna search=");
	scanf("%d",&search);
	result = binary_search(&arr[0],size,search);

	// for printing the result of search
		if (result ==-1){
			printf("Not Found\n");
		}
		else {
			printf("Found at array[%d]= %d \n",result,arr[result]);
		}




	return 0;
}

/*
	Author : Yicheng Shao
	Name: Merge_sort
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct{
	int* arr;
	int* temp;
	int size;
}pack_t;


pack_t* generate_array();
void merge_sort(int* arr, int begin, int end, int* temp);
void merge_array(int* arr, int begin,int mid, int end, int *temp);


void merge_array(int* arr, int begin,int mid, int end, int *temp){
	int i = begin, j = mid;
	int m = mid + 1, n = end;
	int k = 0;

	while(i<=j && m<=n){
		if(arr[i]<=arr[m]){
			temp[k] = arr[i++]; 
		}else{
			temp[k] = arr[m++];
		}
		k++;
	}

	while(i<=j){
		temp[k++] = arr[i++];
	}

	while(m<=n){
		temp[k++] = arr[m++];
	}

	for(i=0; i<k ; i++){
		arr[begin + i] = temp[i];
	}

}

void merge_sort(int* arr, int begin, int end, int* temp){
	if(begin < end){
		int mid = (begin + end) / 2;
		merge_sort(arr,begin,mid,temp);
		merge_sort(arr,mid+1,end,temp);
		merge_array(arr,begin,mid,end,temp);
	}
}

pack_t* generate_array(){
	pack_t* package = malloc(sizeof(pack_t));
	srand( (unsigned)time( NULL ) );
	int size = (rand() % 20) + 10;
	int *arr = (int *)malloc(sizeof(int)*(size));
	int* temp = (int *)malloc(sizeof(int)*(size));
	int i;
	for(i = 0; i<(size);i++){
		arr[i] = rand() % 50;
	}
	package->arr = arr;
	package->temp = temp;
	package->size = size;
	return package;

}

int main(){
	pack_t* package;	
	package = generate_array();
	int i;
	printf("Generated array size: %d\n",package->size);
	for (i = 0; i < package->size; i++)
	{
		printf("%d ", package->arr[i]);
	}
	

	merge_sort(package->arr,0, (package->size)-1, package->temp);
	printf("\nResult: \n");
	for (i = 0; i < package->size; i++)
	{
		printf("%d ", package->arr[i]);
	}
	
	free(package->arr);
	free(package->temp);
	free(package);
	return 1;
}
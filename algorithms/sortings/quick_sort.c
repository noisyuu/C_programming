#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct{
	int* arr;
	int* temp;
	int size;
}pack_t;

pack_t* generate_array();
void quick_sort(int* arr, int lo, int hi);
int partition(int* arr, int lo, int hi);
void swap(int* arr, int i, int j);


void swap(int* arr, int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

pack_t* generate_array(){
	pack_t* package = malloc(sizeof(pack_t));
	srand( (unsigned)time( NULL ) );
	int size = (rand() % 20) + 10;
	int *arr = (int *)malloc(sizeof(int)*(size));
	int* temp = (int *)malloc(sizeof(int)*(size));
	int i;
	for(i = 0; i<(size);i++){
		arr[i] = rand() % 26 + 65; //ASCII code for character from A..Z
	}
	package->arr = arr;
	package->temp = temp;
	package->size = size;
	return package;
}


int partition(int* arr, int lo, int hi){
	int i = lo, j = hi + 1;
	int pivot = arr[lo];
	while(i<j){
		while(arr[++i] < pivot){
			if(i == hi){ 
				break;
			}
		}
		while(arr[--j] > pivot){
			if(j == lo){
				break;
			}
		}
		swap(arr,i,j);
	}
	swap(arr,j,lo);
	return j;
}

void quick_sort(int* arr, int lo, int hi){
	if(lo < hi){
		int j = partition(arr,lo,hi);
		quick_sort(arr,lo,j-1);
		quick_sort(arr,j+1,hi);
	}else{
		return;
	}
}

int main(){
	pack_t* package;	
	package = generate_array();
	int i;
	printf("Generated array size: %d\n",package->size);
	for (i = 0; i < package->size; i++)
	{
		printf("%c ", package->arr[i]);
	}
	

	quick_sort(package->arr,0, (package->size)-1);
	printf("\nResult: \n");
	for (i = 0; i < package->size; i++)
	{
		printf("%c ", package->arr[i]);
	}
	free(package->arr);
	free(package->temp);
	free(package);
	return 1;
}


/*
int main(){
	int a[3] = {1,2,3};
	swap(a,0,2);
	printf("%d", a[0]);
}*/
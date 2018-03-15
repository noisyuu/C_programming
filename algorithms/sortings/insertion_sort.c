/*
	Author : Yicheng Shao
	Name: insertion_sort
*/


//Time complexity O(N^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
	int *arr;
	int size;
}pack_t;

void move_r(int* arr, int index);
pack_t generate_arr();
void insertion_sort(pack_t pack);


void move_r(int* arr, int index){
	int temp = arr[index+1];
	arr[index+1] = arr[index];
	arr[index] = temp;
}

pack_t generate_arr(){
	pack_t package;
	int* arr;
	srand( (unsigned)time( NULL ) );
	int size = (rand() % 20) + 10;
	arr = (int *)malloc(sizeof(int) * size);
	int i;
	for(i = 0; i<size;i++ ){
		arr[i] = rand() % 50;
	}

	package.arr = arr;
	package.size = size;
	printf("SIZE: %d\n",size);
	return package;
}


void insertion_sort(pack_t pack){
	int last_sorted_index = 0, first_unsorted_index;
	int i,j;
	int elem;

	for(first_unsorted_index = 1; first_unsorted_index < pack.size; first_unsorted_index++ ){
		//printf("first_unsorted_index: %d\n", first_unsorted_index);
		elem = pack.arr[first_unsorted_index];
		//printf("element : %d \n", elem);
		//printf("sorted_index: %d\n", last_sorted_index);
		for(i = last_sorted_index; i >= 0; i --){

		//	printf("last_sorted_element : %d \n", pack.arr[i]);
			if(elem < pack.arr[i]){
				move_r(pack.arr,i);
		/**		for(j = 0; j<pack.size ;j++){
					printf("%d ",pack.arr[j]);
				}
				printf("\n");**/
			}else{
				pack.arr[i+1] = elem;
				break;
			}
		}
		last_sorted_index ++;
		
	}
}

int main(int argc, char** argv){
	pack_t array = generate_arr();
	int i;
	for(i = 0; i<array.size ;i++){
		printf("%d ",array.arr[i]);
	}

	//move_r(array.arr,2);
	//move_r(array.arr,3);
	insertion_sort(array);

	printf("\nFinal sorted array: \n");
	
	for(i = 0; i< array.size;i++){
		printf("%d ",array.arr[i]);
	}

	free(array.arr);
	return 0;
	

}
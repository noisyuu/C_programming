#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
//#define SIZE 10

typedef struct data_pack{
	int* a;
	int n;
}pack_t;

int * getRandom();
pack_t arrayGenerator();
void swap(int*,int*);
void selection_Sort(int*,int);

void swap(int* left, int* right){
	int temp;
	temp = *left;
	*left = *right;
	*right = temp;
}

void selection_Sort(int a[],int size){
	int i = 0, j = 0;
	int min;
	int min_index;
	int flag = FALSE;
	for(i = 0; i<size; i++){
		min = a[i];
		for(j=i+1;j<size;j++){
			if(a[j]<min){
				min = a[j];
				min_index = j; 
				flag = TRUE;
			}
		}
		if(flag){
			swap(&a[i],&a[min_index]);
			flag = FALSE;
	 	}
	}
}



pack_t arrayGenerator(){
	//generate a random size array in the range [10,30)
	pack_t package;
	int *result;

	//set the seed
	srand( (unsigned)time( NULL ) );
	int size_r = (rand() % 20) + 10;
	printf("size of array: %d \n", size_r);
	result = (int* )malloc(sizeof(int)*size_r);
	int i;
	for(i = 0;i < size_r;i++){
		result[i] = rand() % 30;
	}	
	package.a = result;
	package.n = size_r;
	return package;
}

/**

In this part, I gotta consider high cohesion

int * getRandom() {

   static int  r[10];
   int i;

   set the seed
   srand( (unsigned)time( NULL ) );
  
   for ( i = 0; i < 10; ++i) {
      r[i] = rand() % 20;
   }

   return r;
}
*/


int main(int argc, char** argv){
	pack_t array;
	array = arrayGenerator();//getRandom();
	int i;
	//int size = sizeof(a)/sizeof(int);
	for(i = 0; i<array.n ;i++){
		printf("%d ",array.a[i]);
	}
	printf("here \n");
	selection_Sort(array.a,array.n);
	for(i = 0; i< array.n;i++){
		printf("%d ",array.a[i]);
	}
	return 0;
}
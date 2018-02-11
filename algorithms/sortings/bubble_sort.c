#include "stdio.h"
#define TRUE 1
#define FALSE 0

void swap(int*,int*);
void bubble_Sort(int*, int);

void swap(int* left, int* right){
	int temp;
	temp = *left;
	*left = *right;
	*right = temp;
}

void bubble_Sort(int a[], int size){
	int i = 0;
	int swapped = FALSE;
	do{
		swapped = FALSE;
		for(i = 0; i<size-1;i++){
			if(a[i]>a[i+1]){
				swap(&a[i],&a[i+1]);	
				swapped = TRUE;
			}
		}
	}while(swapped);
}


int main(int argc, char** argv){
	int a[5] = {3,10,1,20,15};
	int i;
	bubble_Sort(a,5);
	for(i = 0; i< 5;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
/*
	Author : Yicheng Shao
	Name: bubble_Sort
*/


//Time complexity O(N^2)

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
	//do..while loop
	do{
		swapped = FALSE;
		for(i = 0; i<size-1;i++){
			if(a[i]>a[i+1]){
				swap(&a[i],&a[i+1]);	
				swapped = TRUE; //if ever swap method used, checking the whole list
			}
		}
	}while(swapped);
}


int main(int argc, char** argv){
	int a[] = {3,10,1,20,15.9,10,22,13,1};
	int i;
	int size = sizeof(a)/sizeof(int);
	bubble_Sort(a,size);
	for(i = 0; i< size;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
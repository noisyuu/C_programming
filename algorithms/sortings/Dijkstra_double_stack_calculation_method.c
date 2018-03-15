#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*
	using two stacks, one is used to store all the numbers

	these method could only solve problem likes

	(1+((2+3)*(4*5)))

 c*/

#define MAX_INPUT 100
#define false 0
#define true 1

typedef struct{
	int vals[MAX_INPUT];
	int top;
}vals_t;

typedef struct{
	char ops[MAX_INPUT];
	int top;
}ops_t;

int calculation(int len, char *input);
void push(vals_t *vals_stack, int num, ops_t *ops_stack, char c);
int pop_vals(vals_t *vals_stack);
char pop_ops(ops_t *ops_stack);


int main(int argc, char **argv){
	char input[MAX_INPUT];
	while(gets(input)!= NULL){
		int len = strlen(input);
		//printf("%d\n", strlen(input));
		//printf("%c\n", input[0]);
		//printf("%c\n", input[1]);
		calculation(len,input);	
	}
	return 1;
}

int calculation(int len, char *input){
	int i,j = 0 ;
	int flag = false;
	ops_t ops_stack;
	ops_stack.top = -1;
	vals_t vals_stack;
	vals_stack.top = -1;
	if(!(input[len-1] == ')')){
		input[len] = ')';
	}

	for (i = 0; i <= len; i++){
		//printf("current char %c\n", input[i]);
		//printf("current i %d\n", i);
		char temp[12];	
		if(input[i] == '(') {
		}
		else if(input[i] == '+'){
			push(NULL,(int)NULL,&ops_stack,input[i]);
		}
		else if(input[i] == '-'){
			push(NULL,(int)NULL,&ops_stack,input[i]);
		}
		else if(input[i] == '*'){
			push(NULL,(int)NULL,&ops_stack,input[i]);
		}
		else if(input[i] == '/'){
			push(NULL,(int)NULL,&ops_stack,input[i]);
		}
		else if(input[i] == ')'){
			//printf("triggered\n");
			char t = pop_ops(&ops_stack);
			int v = pop_vals(&vals_stack);
			if(t == '+'){
				v = pop_vals(&vals_stack) + v;
			}
			if(t == '-'){
				v = pop_vals(&vals_stack) - v;
			}
			if(t == '*'){
				v = pop_vals(&vals_stack) * v;
			}
			if(t == '/'){
				v = pop_vals(&vals_stack) / v;
			}
			push(&vals_stack,v,NULL,NULL);
		}
		while(isdigit(input[i])){
			flag = true;
			temp[j++] = input[i++];
		}

		if(flag){
			int number = atoi(temp);
			flag = false;
			push(&vals_stack,number,NULL,NULL);
			i--;
		}
		j=0;
		/*
		switch(input[i]){
			case '+':
				symbol
		}
		*/
	}
	printf("final value : %d\n", pop_vals(&vals_stack));
	return 1;
}

void push(vals_t *vals_stack, int num, ops_t *ops_stack, char c){
	if (vals_stack == NULL && ops_stack == NULL){
		printf("Empty arguments");
		return;
	}
	if (vals_stack == NULL){
		if(ops_stack->top <MAX_INPUT){
			ops_stack->top += 1;
			ops_stack->ops[ops_stack->top] = c;
			printf("added %c\n", ops_stack->ops[ops_stack->top]);
		}else{
			printf("operation stack is full \n");
		}
	}
	if (ops_stack == NULL ){
		if(vals_stack->top <MAX_INPUT){
			vals_stack->top += 1;
			vals_stack->vals[vals_stack->top] = num;
			printf("added %d\n", vals_stack->vals[vals_stack->top]);
		}else{
			printf("2 :stack is full \n");
		}
	}
	return;	
	
}

int pop_vals(vals_t *vals_stack){
	if(vals_stack->top == -1){
		printf("Stack is empty!\n");
		return vals_stack->top;
	}

	int num = vals_stack->vals[vals_stack->top];
	printf("poped elmement: %d\n",num);
	vals_stack->top--;
	return num;
}

char pop_ops(ops_t *ops_stack){
	if(ops_stack->top == -1){
		printf("Stack is empty!\n");
		return ops_stack->top;
	}

	char c = ops_stack->ops[ops_stack->top];
	printf("poped elmement: %c\n",c);
	ops_stack->top--;
	return c;
}

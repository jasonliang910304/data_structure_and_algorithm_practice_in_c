#include <stdio.h>
#include <string.h>

#define empty (-1)

int stack[10];
int top = empty;

void push(int num){
	if(top >= 10) return;

	top++;
	stack[top] = num; 
}

void pull(){
	if(top > empty){
		printf("%d", stack[top]);
		top--;
	}
	else if(top == empty)
		printf("the stack is empty");
}

void peek(){
	if(top == empty)
		printf("the stack is empty");
	else
		printf("%d", stack[top]);
}

void peekall(){
	if(top == empty)
		printf("the stack is empty");
	else
		for(int i = top; i > empty; i--){
			printf("%d\n", stack[i]);
		}
}

int main(){
	while(1){
		char act[7];
		int num;
		scanf("%s", act);
		if(strcmp(act, "push") == 0){
			scanf("%d", &num);
			push(num);
		}
		else if(strcmp(act, "pull") == 0)
			pull();
		else if(strcmp(act, "peek") == 0)
			peek();
		else if(strcmp(act, "peekall") == 0)
			peekall();
		else if(strcmp(act, "stop") == 0)
			return 0;
		else 
			printf("please choose a correct action");
	}
	return 0;
}

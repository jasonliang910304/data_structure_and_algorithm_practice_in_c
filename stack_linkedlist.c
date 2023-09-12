#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
	int data;
	struct nodes* next;
}node;

void push(node** top, int value){
	node *newnode = malloc(sizeof(node));
	if(newnode == NULL){
		printf("Memory allocate failed\n");
		exit(1);
	}
	newnode -> data = value;
	newnode -> next = *top;
	*top = newnode;
}

void pop(node** top){
	if(*top == NULL)
		printf("stack is empty");
	else{
		printf("%d", (*top) -> data);
		node* temp = *top;
		*top = (*top) -> next;
		free(temp);
	}
}

int main(){
	node *top = NULL;

	return 0;
}

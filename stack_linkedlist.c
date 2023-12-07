#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes{
	int data;
	struct nodes* next;
}node;

// use double printer because i have to change the top pointer in this function
void push(node** top, int value){
	// allocate a memory space to save a new node
        node *newnode = malloc(sizeof(node));
        // check if the newnode is allocated success or not
	if(newnode == NULL){
		printf("Memory allocate failed\n");
		exit(EXIT_FAILURE);
	}
	newnode -> data = value; //add data to newnode
	newnode -> next = *top;  //put the newnode to current top address
	*top = newnode; //change the top address to the newnode
}

void pop(node** top){
        //check the stack is empty or not at first to prevent pop the NULL out
	if(*top == NULL){
		printf("stack is empty\n");
		return;
	}
	printf("%d\n", (*top) -> data);  //print the data at the top of the stack
	node* temp = *top;  //use temp to save the data in top, if don't use temp we can't free the space later
	*top = (*top) -> next;  //change the top pointer to next node
	free(temp); //free the useless space
}
//this function is use for peek the top data without modifying the stack
void peek(node* top){
	printf("%d\n", top -> data);
}
//this function is used to check all data in the stack. because we don't have to change the top pointer so we just use single pointer
void peekall(node* top){
	node* ptr = top;//declare a pointer to check all data
	while(ptr != NULL){
		printf("%d\n", ptr -> data);//print current data
		ptr = ptr -> next;//change the pointer to next data until the pointer point to NULL
	}
}

int main(){
	node *top = NULL;//because the stack is empty at first so the top is point to NULL
	char act[7];
	while(1){
		int num;
		scanf("%s", act);
		if(strcmp(act, "push") == 0){
			scanf("%d", &num);
			push(&top, num);
		}
		else if(strcmp(act, "pop") == 0)
			pop(&top);
		else if(strcmp(act, "peek") == 0)
			peek(top);
		else if(strcmp(act, "peekall") == 0)
			peekall(top);
		else
			printf("please choose a correct action\n");
	}
	return 0;
}

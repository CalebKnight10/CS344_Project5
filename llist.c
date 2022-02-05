//Caleb Knight
//CS 344
//Programming Exercise in C to parse a command line
//and implement a linked list


#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



// ih -> insert head
// it -> insert tail
// dh -> delete tail
// f  -> free entire list
// p  -> print list to stdout

void parse_command()
{

}

void llist_insert_head(struct node **head, struct node *n) 
{
	//insert node @ head 
	while(*head != NULL) {
		n -> next = *head;
		*head = n;
	}
	*head = n; // if head is NULL then we simply set new node to head

}

struct node *llist_delete_head(struct node **head)
{
	//remove a node from the head
	//return a pointer to it
	//return NULL if empty list
	//doesn't free node, just decouples from list
	if(*head == NULL) {
		return NULL;
	}
	struct node *temporary_node = *head;
	*head = (*head) -> next;
	free(temporary_node);
	return *head;
}

void llist_insert_tail(struct node **head, struct node *n)
{
	//insert node @ tail
	//previously allocated with node_alloc()
}

void llist_print(struct node *head)
{
	//print a list to standard output (stdout)
	//1 -> 12 -> 3490 -> 7
	//no leading or trailing spaces
	//if list is empty print [empty]
	if(head != NULL) {
		printf("%d -> ", head->value);
		head = head -> next;
	} else {
		printf("[empty]\n");
	}
}

void llist_free(struct node **head)
{
	//head will be set to NULL
	if(*head == NULL) {
		return;
	}
	while(*head != NULL) {
		node_free(*head);
	}

}

struct node *node_alloc(int val)
{
	//allocate a new struct node with
	//value 3490 and a next of NULL
	val = 3490;
	struct node *next = NULL;
	return malloc(sizeof(struct node));
}


void node_free(struct node *n)
{
	//free a node that has been allocated
	//by node_alloc()
	free(&n);
}

int main(int argc, char *argv[])
{
	if(argc < 3) {
		printf("Error: Not enough arguments\n");
	} else {
		for(int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "ih") == 0) {
				printf("Insert the following int at the head of the list\n");
			} else if (strcmp(argv[i], "it") == 0) {
				printf("Insert the following int at the tail of the list\n");
			} else if (strcmp(argv[i], "dh") == 0) {
				printf("Delete the node at the tail\n");
			} else if (strcmp(argv[i], "f") == 0) {
				printf("Entire list freed\n");
			} else if (strcmp(argv[i], "p") == 0) {
				printf("List printed to stdout\n");
			}
		}
	}

}
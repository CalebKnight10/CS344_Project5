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
	if(*head != NULL) {
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
	if(*head == NULL) { //if the list is empty then the first node will also be the last
		*head = n;
		return;
	}
	struct node *check_node = *head; //use this node to check if the subsequent node(s) are NULL

	while(check_node -> next != NULL) {  //as long as the node we are checking is not NULL then continue searching for NULL
		check_node = check_node -> next;
	}
	check_node -> next = n;
}

void llist_print(struct node *head)
{
	//print a list to standard output (stdout)
	//1 -> 12 -> 3490 -> 7
	//no leading or trailing spaces
	//if list is empty print [empty]

	if (head == NULL) {
		printf("[empty]\n");
	}
	while(head != NULL) {
		printf("%d -> ", head -> value);
		head = head -> next;
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

struct node *node_alloc(int value)
{
	//allocate a new struct node with
	struct node *new = NULL;

	new = malloc(sizeof(struct node));

	new -> value = value;
	new -> next = NULL;
	
	return new;
}


void node_free(struct node *n)
{
	//free a node that has been allocated
	//by node_alloc()
	free(&n);
}

int main(int argc, char *argv[])
{
    struct node *head = NULL;


	if(argc < 2) {
		printf("Error: Not enough arguments\n");
	} else {
		for(int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "ih") == 0) {
				printf("Insert the following int at the head of the list\n");

				int value = atoi(argv[++i]);
				struct node *new_node = node_alloc(value);
				printf("atoi is: %d\n", value);
				printf("new node is: %d\n", new_node->value);

				llist_insert_head(&head, new_node); 
			} else if (strcmp(argv[i], "it") == 0) {
				printf("Insert the following int at the tail of the list\n");

				int value = atoi(argv[++i]);
				struct node* new_node = node_alloc(value);

				llist_insert_tail(&head, new_node);
			} else if (strcmp(argv[i], "dh") == 0) {
				printf("Delete the node from the head\n");

				llist_delete_head(&head);
			} else if (strcmp(argv[i], "f") == 0) {
				printf("Entire list freed\n");

				llist_free(&head);
			} else if (strcmp(argv[i], "p") == 0) {
				printf("List printed to stdout\n");

				llist_print(head);
			}
		}
	}

}
//Caleb Knight
//CS 344
//Programming Exercise in C to parse a command line
//and implement a linked list


#include "llist.h"
#include <stdlib.h>


// ih -> insert head
// it -> insert tail
// dh -> delete tail
// f  -> free entire list
// p  -> print list to stdout

void llist_insert_head(struct node **head, struct node *n) 
{
	//insert node @ head 
	//need to have called node with node_alloc()
}

struct node *llist_delete_head(struct node **head)
{
	//remove a node from the head
	//return a pointer to it
	//return NULL if empty list
	//doesn't free node, just decouples from list
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
}

void llist_free(struct node **head)
{
	//call node_free() for every node in the list
	//head will be set to NULL
}

struct node *node_alloc(int value)
{
	//allocate a new struct node with
	//value 3490 and a next of NULL
}


void node_free(struct node *n)
{
	//free a node that has been allocated
	//by node_alloc()
}

void main(int argc, char *argv[])
{

}
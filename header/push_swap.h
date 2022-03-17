#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes, remember to remove stdio later
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//linked list
typedef struct nodes
{
	int	position;
	int	value;
	struct nodes	*previous;
	struct nodes	*next;
	struct nodes	*first;
	struct nodes	*last;
} node;

//functions nodes implementation
node	*new_node(int value);
void	add_element(node **stack_a, int value);
void	show_elements(node *stack_a);//use ftprintf
void	clear_elements(node **stack_a);//use ftprintf
int	list_size(node *stack_a);
node	*duplicate_node(node *old); //it's useless so far
//move operations
void	sa(node **stack_a);
void	sb(node **stack_b); //basically the same as sa.c
void	ss(node **stack_a, node **stack_b);
#endif

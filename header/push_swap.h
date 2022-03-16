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
void	add_element(node *stack_a, int value);
#endif

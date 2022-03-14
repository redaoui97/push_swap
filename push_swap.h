#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes, remember to remove stdio later
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//linked list
typedef struct nodes
{
	int	size;
	int	position;
	int	value;
	node	*previous;
	node	*next;
	node	*first;
	node	*last;
	int	is_empty;
} node;
#endif

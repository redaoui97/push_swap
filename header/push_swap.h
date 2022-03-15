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
	int	is_empty;
} node;

//function
//s
#endif

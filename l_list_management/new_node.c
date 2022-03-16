#include "../header/push_swap.h"

// allocates a new node and returns a pointer to it

node	*new_node(int value)
{
	node	*n;

	n = (node *)malloc(sizeof(node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	n->previous = NULL;
	n->position = 0;
	n->first = NULL;
	n->last = NULL;
	return (n);
}

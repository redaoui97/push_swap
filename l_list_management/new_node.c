#include "../header/push_swap.h"

node	*new_node(int value)
{
	node	*n;

	n = (node)malloc(sizeof(node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	n->previous = NULL;
	n->position = 0;
	n->first = n;
	n->last = NULL;
	n->is_empty = 0;
	return (n);
}

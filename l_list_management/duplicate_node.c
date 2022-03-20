#include "../header/push_swap.h"

node	*duplicate_node(node *old)
{
	node	*new;

	new = new_node(0);
	new->position = old->position;
	new->value = old->value;
	new->next = old->next;
	new->previous = old->previous;
	new->first = old->first;
	new->last = old->last;
	return (new);
}

/*int main(void)
{
	node *old;
	node *new;
	node test;
	
	old = new_node(0);
	//3mr
	old->value = 69;
	old->position = 96;
	old->next = &test;
	old->previous = &test;
	old->first = &test;
	old->last = &test;
	//sala t3mar
	new = duplicate_node(old);
	printf("address test:%p\nvalue:%d\nposition:%d\nnext:%p\nprevious:%p\nfirst:%p\nlast:%p",&test,new->value,new->position,new->next,new->previous,new->first,new->last);
	return 0;
}*/

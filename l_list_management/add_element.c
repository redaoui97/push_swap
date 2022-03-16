#include "../header/push_swap.h"

//creates a node and adds it to the top of the list

void	add_element(node *stack_a, int value)
{
	node	*new;
	
	new = new_node(value);
	new->previous = NULL;
	new->first = new;
	if(!stack_a)
	{
		new->next = NULL;
		new->last = new;
		return ;
	}
	new->next = stack_a;
	new->last = stack_a->last;
	stack_a->previous = new;
	while (stack_a)
	{
		stack_a->position++;
		stack_a->first = new;
		stack_a = stack_a->next;
	}
}
int main(void)
{
	printf("heello\n");
	return 0;
}

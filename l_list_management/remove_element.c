#include "../header/push_swap.h"

//removes a node from the list

void	remove_element(node **stack_a)
{
	node	*ptr;
	node	*ptr_next;

	ptr = *stack_a;
	if (list_size(*stack_a) == 1)
	{
		free(*stack_a);
		return ;
	}
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	while (*stack_a)
	{
		(*stack_a)->position--;
		(*stack_a)->first = ptr_next;
		*stack_a = (*stack_a)->next;
	}
	free (ptr);
	*stack_a = ptr_next;
}

#include "../header/push_swap.h"

//removes a node from the list

void	remove_element(node **stack_a, int position)
{
	node	*ptr;
	node	*ptr_next;

	ptr = *stack_a;
	if (*stack_a != (*stack_a)->first)//I can delete it 
		return ;
	if (list_size(*stack_a) == 1)
	{
		free(*stack_a);
		return ;
	}
	(*stack_a)->next->previous = NULL;
	while (*stack_a)
	{
		(*stack_a)->next = ptr_next;
		*stack_a = (*stack_a)->next;
	}
	free (ptr);
}

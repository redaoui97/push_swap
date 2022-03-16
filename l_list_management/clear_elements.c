#include "../header/push_swap.h"

//frees all the elements of the stack

void	clear_elements(node **stack_a)
{
	node *perm;
	
	while(*stack_a)
	{
		printf("element at position: %d cleared\n",(*stack_a)->position);
		perm = (*stack_a)->next;
		free (*stack_a);
		*stack_a = perm;
	}
}

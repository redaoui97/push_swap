#include "../header/push_swap.h"

//returns the size of the list

int	list_size(node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

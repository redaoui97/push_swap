#include "../header/push_swap.h"

void	pa(node **stack_a, node **stack_b)
{
	add_element(&*stack_a, (*stack_b)->value);
	remove_element(&*stack_b);	
}

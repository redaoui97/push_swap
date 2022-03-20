#include "../header/push_swap.h"*

void	pb(node **stack_a, node **stack_b)
{
	add_element(&*stack_b, (*stack_a)->value);
	remove_element(&*stack_a);
}

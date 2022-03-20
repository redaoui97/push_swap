#include "../header/push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of the stack a

void	sa(node **stack_a)
{
	int	permu;

	if (list_size(*stack_a) < 2)
		return;
	permu = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = permu;
}

/*int main(void)
{
	node *stack_a;
	
	stack_a = NULL;
	add_element(&stack_a, 5);
	add_element(&stack_a, 4);
	add_element(&stack_a, 3);
	add_element(&stack_a, 2);
	add_element(&stack_a, 1);
	show_elements(stack_a);
	printf("----------\n");
	ss(&stack_a,&stack_a);
	show_elements(stack_a);
	clear_elements(&stack_a);
	return 0;
}*/

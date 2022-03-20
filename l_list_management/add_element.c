#include "../header/push_swap.h"

//creates a node and adds it to the top of the list

void	add_element(node **stack_a, int value)
{
	node	*new;

	new = new_node(value);
	new->previous = NULL;
	new->first = new;
	if(!(*stack_a))
	{
		new->next = NULL;
		new->last = new;
		*stack_a=new;
		return ;
	}
	new->next = *stack_a;
	new->last = (*stack_a)->last;
	(*stack_a)->previous = new;
	while (*stack_a)
	{
		(*stack_a)->position++;
		(*stack_a)->first = new;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = new;
}
int main(void)
{
	node *stack_a;
	node *stack_b;
	
	stack_a = NULL;//always initialize with NULL otherwise hh
	stack_b = NULL;
	add_element(&stack_a, 4);
	add_element(&stack_a, 3);
	add_element(&stack_a, 2);
	add_element(&stack_a, 1);
	add_element(&stack_a, 0);
	show_elements(stack_a);
	printf("-----------\n");
	pb (&stack_a, &stack_b);
	printf("---------a\n");
	show_elements(stack_a);
	printf("---------b\n");
	show_elements(stack_b);
	printf("----------------\n");	
	pa (&stack_a, &stack_b);
	printf("-------again\n");
	show_elements(stack_a);
	printf("---b\n");
	show_elements(stack_b);
	clear_elements(&stack_b);
	clear_elements(&stack_a);
	return 0;
}

#include "../header/push_swap.h"

void show_elements(node *stack_a)
{
	while (stack_a)
	{
		printf("%d:%d\n",stack_a->position,stack_a->value);
		stack_a = stack_a->next;
	}
}

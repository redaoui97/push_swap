#include "../header/push_swap.h"

void show_elements(node *stack_a)
{
	while (stack_a)
	{
		printf("%p:%p:%d:%d\n",stack_a,stack_a->next,stack_a->position,stack_a->value);
		stack_a = stack_a->next;
	}
}

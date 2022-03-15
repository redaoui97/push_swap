#include "../header/push_swap.h"

void	add_element(node stack_a, node stack_b, int value)
{
	node	new;

	if(!stack_a || !stack_b)
		return ;
	new.size = stack_a->size + 1;
	new.position = 0;
	new.value = value;
	new.previous = NULL;
	new.next = stack_a;
	new.first = new;
	new.last = stack_a->last;
	new.is_empty = 0;
	while (stack_a->next)
	{
		stack_a->size++;
		stack_a->position++;
		stack_a->
		stack_a = stack_a->next;
	}	
}
int main(void)
{
	printf("heello\n");
	return 0;
}

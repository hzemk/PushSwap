#include "pushswap.h"

int disorder(t_stack *a)
{
	int i;
	int j;
	int total;
	int size;
	int messy;
	int *arr;
	t_node *node;

	node=a->top;
	size= a->size;
	arr=malloc(sizeof(int)* size);
	if(!arr)
		return(0);
	i=0;
	while(node)
	{
		arr[i] = node->data;
		i++;
		node=node->next;
	}
	i=0;
	total=0;
	messy=0;
	while (i < size)
	{
		j=i+1;
		while (j < size)
		{
			total+=1;
			if( arr[i] > arr[j])
				messy+=1;
			j++;
		}
		i++;
	}
	free(arr);
	return ((double)messy/total);
}

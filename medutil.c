#include "pushswap.h"
#include <math.h>

int	*stack_toarr(t_stack *a)
{
	int n;
	int *arr;
	t_list *node;

	n=a->size;
	arr=(int *)malloc(sizeof(int) * n);
	if(!arr)
		return (0);
	node=a->top;
	i=0;
	while(node)
	{
		arr[i]=node->content;
		i++;
		node=node->prev;//prev
	}
	return(arr);
}

void sort_arr(int *arr, int n)//n=size of stack
{
	int min;
	int i;

	i=0;
	while (i < n-1)
	{
		int j=0;
		while (j < (n - i - 1))// 0,2,3,7,8,9
		{
			if(arr[j] > arr[j+1])
			{	
				min=arr[j];
				arr[j]=arr[j + 1];
				arr[j + 1]=min;
			}
			j++;	
		}
		i++;
	}
}
t_chunk *create_chunks(int *sorted, int chunk_count, int n)
{
	t_chunk *chunks;
	int len;
	int i;
	int min;
	int max;

	chunks=malloc(sizeof(int) * chunk_count);
	if(!chunk)
		return(0);
	len= n / chunk_count;
	i=0;
	while(i < chunk_count)
	{
		chunk->min=sorted[i * len];//min= 0 * 10=0 index [0]=min/exmpl
		if(i == (chunk_count - 1))//if we got stack size of 100,  then 10 chunks and range 10//if i= 9 last index so maxi=arr[100-1]exmpl tho 
			chunks->max=sorted[n -1];//each chunk has custome range tho it would stop at 10 eachtime
		else
			chunks->max=sorted[(i * 1) * (len - 1)]//else maxi=last index of the chunk
		i++;
	}
	return (chunk);
}

int count_chunks(int n)
{
    int i = 0;
    while (i * i <= n)
        i++;
    return i - 1;
}
void push_toB(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int size;
	int i;
	int top;

	i=0;
	size=a->size;
	while(i < size)
	{
		top=a->top;
		if(top >= chunks->min && top <= chunks->max)
			pb(a, b);
		else
			rra(a);
	}
}

void push_toA(t_stack *a, t_stack *b)
{
	int maxi;

	while(b->size)
	{
		maxi=find_max(b);
		while(b->top != maxi)
		{
			if(find-index(b, maxi) <= (b->size/2))
				rrb(b);
			else
				rb(b);
		}
		pa(a, b);
	}
}

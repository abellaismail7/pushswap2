#include "pushswap.h"

int is_sorted(t_stack *st, int asc)
{
	int i;
	int last;

	i = 1;
	last = st->arr[0];

	while (i < st->len)
	{
		if ((st->arr[i] > last) != asc)
			return 0;
		last = st->arr[i];
		i++;
	}
	return 1;
}

void ft_quicksort(int *arr, int left)
{
	int last;
	int right;
	int index;

	if (left <= 1)
		return ;
	last = arr[left - 1];
	index = 0;
	right = 0;
	while (right < left)
	{
		if(arr[right] <= last)
		{
			swap(arr, index, right);
			index++;
		}
		right++;
	}
	ft_quicksort(arr, index -1 );
	ft_quicksort(arr + index, left - index);
}

void iquicksort(int *arr, int *iarr, int left)
{
	int last;
	int right;
	int index;

	if (left <= 0)
		return ;
	last = arr[left - 1];
	index = 0;
	right = 0;
	while (right < left)
	{
		if(arr[right] <= last)
		{
			swap(arr, index, right);
			swap(iarr, index, right);
			index++;
		}
		right++;
	}
	iquicksort(arr, iarr, index - 1);
	iquicksort(arr + index + 1, iarr + index + 1, left - index - 1);
}

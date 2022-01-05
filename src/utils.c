#include <stdlib.h>
#include "stack.h"
#include "common.h"

void swap(int *arr, int i1, int i2)
{
	int tmp;

	tmp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = tmp;
}

int has_dup(t_stack * st)
{
	int i;
	int j;

	i = 0;
	while(i < st->len)
	{
		j = i + 1;
		while(j < st->len)
		{
			if (st->arr[i] == st->arr[j])
				return 1;
			j++;
		}
		i++;
	}

	return 0;
}

int append_int(int *res, char c, int sign)
{
	int _num;
	int min;

	if(c < '0' || c > '9')
		return 0;
	_num = *res * 10 - (c - '0');
	min = 1 << 31;
	if(_num > *res || (_num == min && sign == 1))
		return 0;

	*res = _num;
	return 1;
}

int	ft_atoi(char *str, int *res)
{
	int	sign;

	sign = -1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	*res = 0;
	while (*str && append_int(res, *str, sign * -1))
		str++;
	if (*str != 0)
		return 0;
	*res *= sign;
	return 1;
}

int *incarr(int size)
{
	int *arr;
	int i;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return NULL;
	i  = 0;
	while (i < size)
	{
		arr[i] = i;
		i++;
	}
	return arr;
}

int *av2int(char **av, int size)
{
	int	*arr;
	int res;
	int i;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return NULL;
	i = 0;
	while (i < size)
	{
		if(!ft_atoi(av[i], &res))
		{
			free(arr);
			return NULL;
		}
		arr[size - i - 1] = res;
		i++;
	}
	return arr;
}

t_stack clone_st(t_stack *st)
{
	int i;
	t_stack nst;

	nst.capacity = 0;
	nst.arr = malloc(sizeof(int) * st->capacity);
	if (nst.arr == NULL)
		return nst;

	nst.len = st->len;
	nst.capacity = st->capacity;
	i = 0;
	while(i < nst.len)
	{
		nst.arr[i] = st->arr[i];
		i++;
	}
	return nst;
}

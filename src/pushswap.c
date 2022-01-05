/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:01:35 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/04 10:01:35 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"
#include "common.h"
#include "stack.h"
#include <stdio.h>

t_INSTRA checkbestInstra(t_stack *st, int asc, int max)
{
	if (st->len < 2 && is_sorted(st, asc))
		return NONE;
	
	if (st->arr[st->len - 1] == max)
		return _R;

	if ((st->arr[st->len - 1] > st->arr[st->len - 2]) == asc)
		return _R;
	else
		return _S;
}

int doInstra(t_data *data, t_INSTRA i1, t_INSTRA i2)
{
	if (i1 == NONE && i2 == NONE)
		return 0;
	if ((i1 & i2) == _R)
		swipeup(data);
	else if((i1 & i2) == _S)
		swapab(data);
	else if((i1 & i2) == _RR)
		swipedown(data);
	else
	{
		if(i1 == RA)
			swipeupa(data);
		else if(i1 == SA)
			swapa(data);
		else if(i1 == RRA)
			swipedowna(data);
		else if(i1 == PA)
			pusha(data);

		if(i2 == RB)
			swipeupb(data);
		else if(i2 == SB)
			swapb(data);
		else if(i2 == RRB)
			swipedownb(data);
		else if(i2 == PB)
			pushb(data);
	}

	return 1;
}

int ft_pushswap (t_data *data)
{
	t_INSTRA i1;
	t_INSTRA i2;
	int half =  data->arrpos.len / 2 - 1;
	int med = data->arrpos.arr[half];

	while(data->sta.len > half + 1)
		push_half(data, med);

	while (1)
	{
		i1 = checkbestInstra(&data->sta, 0, data->arrpos.arr[data->arrpos.len - 1]) | _A;
		i2 = checkbestInstra(&data->stb, 1, half) | _B;
    	
		if(!doInstra(data, i1, i2))
			break ;
	}

	pushback(data);
	return 0;
}

int data_setup(int size, char **av)
{
	t_data data;

	data.print_inst = 1;
	data.sta = stack_wrap(av2int(av, size), size, size);
	data.stb = stack_wrap(malloc(sizeof(int) * size), 0, size);
	if (has_dup(&data.sta) || data.sta.arr == 0 ||  data.stb.arr == 0)
	{
		ft_putstrfd(2, "Error\n");
		free(data.sta.arr);
		free(data.stb.arr);
		return 1;
	}
	data.arrpos = clone_st(&data.sta); // protection
	ft_quicksort(data.arrpos.arr, data.arrpos.len);
	ft_pushswap(&data);
	free(data.sta.arr);
	free(data.stb.arr);
	return 0;
}

int main(int ac, char **av)
{
	return (data_setup(ac - 1, av + 1));
}


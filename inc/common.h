/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:01:36 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/03 11:01:36 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "pushswap.h"

typedef enum e_INSTRA {
	NONE	= 0,
	_A		= 0b000001,
	_B		= 0b000010,

	SA		= 0b000101,
	SB		= 0b000110,
	_S		= 0b000100,

	PA		= 0b001001,
	PB		= 0b001010,
	_P		= 0b001000,

	RA		= 0b010001,
	RB		= 0b010010,
	_R		= 0b010000,

	RRA		= 0b100001,
	RRB		= 0b100010,
	_RR		= 0b100000,

	SS		= 5555,
	RR		= 6666,
	RRR		= 7777,
}	t_INSTRA;

int		swapa(t_data *data);
int		swapb(t_data *data);
int		swapab(t_data *data);

int		pusha(t_data *data);
int		pushb(t_data *data);

int		swipeupa(t_data *data);
int		swipeupb(t_data *data);
int		swipeup(t_data *data);

int		swipedowna(t_data *data);
int		swipedownb(t_data *data);
int		swipedown(t_data *data);

int		instra_s(t_stack *st);
int		instra_p(t_stack *st1, t_stack *st2);
int		instra_r(t_stack *st);
int		instra_rr(t_stack *st);

int		ft_strcmp(char *s1, char *s2);

t_stack	stack_wrap(int *arr, int cap, int len);
t_stack	clone_st(t_stack *st);
void	iquicksort(int *arr, int *iarr, int left);
void	ft_quicksort(int *arr, int left);

#endif

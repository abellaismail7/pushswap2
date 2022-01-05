#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "stack.h"
typedef struct s_data
{
	int print_inst;
	t_stack sta;	
	t_stack stb;	
	t_stack arrpos;
	int size;
} t_data;

int ft_strlen(char *str);
void ft_putstrfd(int fd, char *str);
int *av2int(char **av, int size);
void swap(int *arr, int a, int b);
int nextinstra(t_data *data);
int pushback(t_data *data);
int has_dup(t_stack * st);
int is_sorted(t_stack *st, int asc);
void ft_quicksort(int *arr, int left);

void push_half(t_data *data, int med);
void printst(t_stack *st);
#endif // !PUSHSWAP_H

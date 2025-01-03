/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:53:58 by tchow-so          #+#    #+#             */
/*   Updated: 2025/01/03 11:44:29 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

# include "../libs/libft/libft/libft.h"

typedef struct s_elem
{
	int				val;
	int				i;
	bool			median;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_info
{
	int	min;
	int	max[5];
	int	median;
	int	size;
}	t_info;

typedef struct s_moves
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	cost;
}	t_moves;

/* ======================= PARSING & ERROR HANDLING ========================= */
char	**check_input(int argc, char **argv);
int		check_space(char *str);
void	check_nodup(int argc, char **argv);
void	printerr_exit(void);
long	ft_atol(const char *str);

/* ============================= STACK UTILS ================================ */
// List initiation
void	stack_init(int argc, char **argv, t_elem **a);
void	add_elem(t_elem **stack, t_elem *elem);
// General use
int		stack_size(t_elem **stack);
void	stack_dup(t_elem **stack, t_elem **dup);
t_elem	*stack_max(t_elem **stack);
t_elem	*stack_last(t_elem **stack);
t_elem	*stack_min(t_elem **stack);

/* ======================= INSTRUCTIONS (OPERATIONS) ======================== */
// Swap
void	sa(t_elem **a);
void	sb(t_elem **b);
void	ss(t_elem **a, t_elem **b);
// Push
void	pa(t_elem **a, t_elem **b);
void	pb(t_elem **a, t_elem **b);
// Rotate
void	ra(t_elem **a);
void	rb(t_elem **b);
void	rr(t_elem **a, t_elem **b);
// Reverse rotate
void	rra(t_elem **a);
void	rrb(t_elem **b);
void	rrr(t_elem **a, t_elem **b);

/* ================================ SORTING ================================= */
// Sorting
void	sort_nano(int size, t_elem **a, t_elem **b);
void	sort_two(t_elem **a);
void	sort_three(t_elem **a);
void	sort_four(t_elem **a, t_elem **b);
void	sort_five(t_elem **a, t_elem **b);
void	sort_any(int size, t_elem **a, t_elem **b);
// Algorithms
void	quicksort(t_elem **stack, t_elem *head, t_elem *tail);
// Utils - General use
int		sort_check(t_elem **stack);
// Algorithm utils – Stacks bigger than 5 elements
void	find_key_values(int size, t_elem **a, t_info *info);
void	set_info(t_elem *dup, t_info *info, int size);
void	push_median(t_info info, t_elem **a, t_elem **b);
void	push_presort(t_info info, t_elem **a, t_elem **b);
void	calc_ops(t_elem **a, t_elem **b, t_moves *moves);
void	sum_ops(t_moves *option);
void	choose_option(t_moves option, t_moves *moves);

/* ================================ MEMORY ================================= */
void	free_strarray(char **array);
void	free_stack(t_elem **stack);

#endif

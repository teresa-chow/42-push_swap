/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:53:58 by tchow-so          #+#    #+#             */
/*   Updated: 2024/08/08 14:37:22 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include "../libs/libft/libft/libft.h"

/* typedef struct	s_stack
{
	int	*node_index;
	int	len;
}		t_stack; */

typedef struct	s_elem
{
	int		value;
	//int		current_index;
	//int		final_index;
	//int		cost;
	//int		above_median;
	//int		cheapest;
	//struct s_elem	*target_node;
	struct s_elem	*next;
	struct s_elem	*prev;
}		t_elem;

/* ======================= PARSING & ERROR HANDLING ========================= */
char	**check_input(int argc, char **argv);
int	check_space(char *str);
void	check_nodup(char **argv);
void	printerr_exit(void);
long	ft_atol(const char *str);

/* ============================= STACK UTILS ================================ */
void    stack_init(int argc, char **argv, t_elem **a);
// Node initiation
// General use
//int	stack_size(t_elem **stack);
//t_elem	*stack_last(t_elem **stack);
//t_elem	*stack_max(t_elem **stack);
//t_elem	*stack_min(t_elem **stack);

/* ======================= INSTRUCTIONS (OPERATIONS) ======================== */
// Swap
//void	sa(t_elem **a);
//void	sb(t_elem **b);
//void	ss(t_elem **a, t_elem **b);
// Push
//void	pa(t_elem **a, t_elem **b);
//void	pb(t_elem **a, t_elem **b);
// Rotate
//void	ra(t_elem **a);
//void	rb(t_elem **b);
//void	rr(t_elem **a, t_elem **b);
// Reverse rotate
//void	rra(t_elem **a);
//void	rrb(t_elem **b);
//void	rrr(t_elem **a, t_elem **b); 

/* ================================ SORTING ================================= */
// Utils
//int	sort_check(t_elem *stack);
// Algorithms
//void	sort_nano(t_elem **a, t_elem **b);
//void	sort_two(t_elem **a);
//void	sort_three(t_elem **a);
//void	sort_four(t_elem **a, t_elem **b);
//void	sort_five(t_elem **a, t_elem **b); 
//void	sort_any(t_elem **a, t_elem **b); // TODO

/* ================================ MEMORY ================================= */
//void    free_strarray(char **array);

#endif

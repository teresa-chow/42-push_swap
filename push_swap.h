/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:53:58 by tchow-so          #+#    #+#             */
/*   Updated: 2024/07/22 17:32:16 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <limits.h> // INT_MIN + INT_MAX
# include <unistd.h>

# include "libft/libft/libft.h"

/* typedef struct	s_stack
{
	int	*node_index;
	int	len;
}		t_stack; */

typedef struct	s_stack_node
{
	int		value;
	int		current_index;
	int		final_index;
	int		cost;
	int		above_median;
	int		cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}		t_stack_node;

/* =============================== PARSING ================================== */


/* =========================== ERROR HANDLING =============================== */


/* ================================ UTILS =================================== */
// Stack initiation
// Node initiation
// Stack utils
int	stack_size(t_stack_node **stack);
t_stack_node	*stack_last(t_stack_node **stack);


/* ============================== INSTRUCTIONS ============================== */
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b); 

/* ================================ SORTING ================================= */
// Utils
int	sort_check(t_stack_node *stack);
// Sorting algorithms
void	sort_two(t_stack_node **a);
void	sort_three(t_stack_node **a);
void	sort_four(t_stack_node **a, t_stack_node **b);
void	sort_five(t_stack_node **a, t_stack_node **b);
void	sort_any(t_stack_node **a, t_stack_node **b);

#endif

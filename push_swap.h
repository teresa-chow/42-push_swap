/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:53:58 by tchow-so          #+#    #+#             */
/*   Updated: 2024/06/06 14:36:57 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <limits.h> // INT_MIN + INT_MAX
# include <stdbool.h> // true + false
# include <unistd.h>

# include "libft/libft/libft.h"

typedef struct	s_stack_node
{
	int		value;
	int		current_index;
	int		final_index;
	int		cost;
	bool		above_median;
	bool		cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}		t_stack_node;

// Handle errors
// Stack initiation
// Node initiation

// STACK UTILS
int	stack_size(t_stack_node **stack);
t_stack_node	*stack_last(t_stack_node **stack);


// COMMANDS
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
pa
pb
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
rra
rrb
rrr

// Algorithms

#endif

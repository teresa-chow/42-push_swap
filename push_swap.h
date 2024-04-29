/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:53:58 by tchow-so          #+#    #+#             */
/*   Updated: 2024/04/29 14:46:30 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

# include "libft/libft/libft.h"

typedef struct	s_stack_node
{
	int		value;
	int		current_position;
	int		final_index;
	int		push_price;
	bool		above_median;
	bool		cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}		t_stack_node;

#endif

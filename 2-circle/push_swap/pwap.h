/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:16 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:52:17 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWAP_H
# define PWAP_H

# include <stdlib.h>
# include <unistd.h> 
# include "./libft/libft.h"

# define MAX_LEN	1000000
# define SA			1
# define SB			2
# define SS			3
# define PA			4
# define PB			5
# define RA			6
# define RB			7
# define RR			8
# define RRA		9
# define RRB		10
# define RRR		11

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	int				data;
}	t_node;

typedef struct s_ds
{
	int		ac;
	char	*av[MAX_LEN];
	t_node	*a;
	t_node	*b;
	int		arr[MAX_LEN];
	int		cmd[MAX_LEN];
	int		len_a;
	int		len_b;
	int		len_arr;
	int		len_cmd;
	int		dist_a;
	int		dist_b;
}	t_ds;

int			parse(int argc, char **argv, t_ds *store);
void		input(t_ds *store);
void		pre_sort(t_ds *store);
int			valid1(t_ds *store);
int			valid2(t_ds *store);
void		push_front(t_node **head, int data);
void		push_back(t_node **head, int data);
int			pop_front(t_node **head);
int			pop_back(t_node **head);
int			front(t_node *head);
int			back(t_node *head);
int			next(t_node *head);
void		swap_a(t_ds *store);
void		swap_b(t_ds *store);
void		push_a(t_ds *store);
void		push_b(t_ds *store);
void		rotate_a(t_ds *store);
void		rotate_b(t_ds *store);
void		rotate_r(t_ds *store);
void		rerotate_a(t_ds *store);
void		rerotate_b(t_ds *store);
void		rerotate_r(t_ds *store);
void		_sort(int *arr, int n);
void		_swap(int *a, int *b);
long long	_max(long long a, long long b);
long long	_min(long long a, long long b);
long long	_abs(long long a);
void		trim(t_ds *store);
void		organize(t_ds *store);
void		reflect(t_ds *store);
int			is_sorted(t_ds *store);
void		init(t_ds *store);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 07:08:58 by tkong             #+#    #+#             */
/*   Updated: 2022/08/12 11:28:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define UINT32			unsigned int
# define UINT64			unsigned long long
# define MAX_SIZE		1000000000

# define FLAG_MINUS		1u
# define FLAG_PLUS		2u
# define FLAG_SPACE		4u
# define FLAG_SHARP		8u
# define FLAG_ZERO		16u

# define WID_NUM		1u
# define WID_STAR		2u

# define PREC_DOT		1u
# define PREC_NUM		2u
# define PREC_STAR		4u

# define LEN_H			1u
# define LEN_HH			2u
# define LEN_L			4u
# define LEN_LL			8u
# define LEN_J			16u
# define LEN_Z			32u
# define LEN_T			64u
# define LEN_L_UP		128u

# define SPEC_D_OR_I	1u
# define SPEC_U			2u
# define SPEC_O			4u
# define SPEC_X			8u
# define SPEC_X_UP		16u
# define SPEC_F			32u
# define SPEC_F_UP		64u
# define SPEC_E			128u
# define SPEC_E_UP		256u
# define SPEC_G			512u
# define SPEC_G_UP		1024u
# define SPEC_A			2048u
# define SPEC_A_UP		4096u
# define SPEC_C			8192u
# define SPEC_S			16384u
# define SPEC_P			32768u
# define SPEC_N			65536u
# define SPEC_PERCENT	131072u

typedef struct s_elem
{
	UINT32		flag;
	UINT32		wid;
	UINT32		prec;
	UINT32		len;
	UINT32		spec;
	int			width;
	int			precis;
	char		res[MAX_SIZE];
	int			begin;
	int			end;
	int			neg;
}	t_elem;

int			ft_printf(const char *format, ...);
int			ft_vfprintf(const char *format, va_list ap);
void		set_arg_value(va_list ap, t_elem *info);
int			scan_flag(const char *form, int idx, t_elem *info);
int			scan_wid(const char *form, int idx, t_elem *info);
int			scan_prec(const char *form, int idx, t_elem *info);
int			scan_len(const char *form, int idx, t_elem *info);
int			scan_spec(const char *form, int idx, t_elem *info);
int			is_flag(int c);
int			is_wid(int c);
int			is_prec(int c);
int			is_len(int c);
int			is_spec(int c);
int			is_spec_part1(int c);
int			is_spec_part2(int c);
int			check_flag(t_elem *info);
int			check_wid(t_elem *info);
int			check_prec(t_elem *info);
int			check_len(t_elem *info);
int			check_spec(t_elem *info);
int			check_combi_minus(t_elem *info);
int			check_combi_plus(t_elem *info);
int			check_combi_space(t_elem *info);
int			check_combi_sharp(t_elem *info);
int			check_combi_zero(t_elem *info);
void		itodec(t_elem *info, int i);
void		utodec(t_elem *info, UINT32 u);
void		ulltohex(t_elem *info, UINT64 ull, int up);
void		ptohex(t_elem *info, void *p);
void		apply_prec(t_elem *info);
void		apply_base(t_elem *info);
void		apply_wid(t_elem *info);
void		apply_sign(t_elem *info);
long long	_abs(long long ll);
void		_rev(char *str, int begin, int end);
void		_swap(char *a, char *b);

#endif

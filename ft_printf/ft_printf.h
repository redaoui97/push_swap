/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:50:10 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/11 21:02:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *f, ...);
int		print_addresse(unsigned long int adr);
int		print_char(char chr);
int		print_nbr(int nbr);
int		print_hex_lower(unsigned int nbr);
int		print_hex_upper(unsigned int nbr);
int		print_nbr_unsigned(unsigned int nbr);
int		print_str(char *str);
size_t	ft_strlen(const char *str);
#endif

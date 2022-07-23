/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:18:22 by rbatson           #+#    #+#             */
/*   Updated: 2022/01/06 18:39:19 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putnbr(int num);
int	ft_putaddress(unsigned long int nb);
int	ft_puthexadecimal(unsigned int nb, int s);
int	ft_putunsigned(unsigned int nb);
#endif

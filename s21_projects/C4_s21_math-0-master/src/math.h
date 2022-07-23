/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:30:19 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/18 23:00:27 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

// #include <errno.h>
// #include <float.h>
// #include <stdbool.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define EPS 1e-6;

int			s21_abs(int x);
long double	s21_acos(double x);
long double	s21_asin(double x);
long double	s21_atan(double x);
long double	s21_ceil(double x);
long double	s21_cos(double x);
long double	s21_exp(double x);
long double	s21_fabs(double x);
long double	s21_floor(double x);
long double	s21_fmod(double x, double y);
long double	s21_log(double x);
long double	s21_pow(double base, double exp);
long double	s21_sin(double x);
long double	s21_sqrt(double x);
long double	s21_tan(double x);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:28:29 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/23 15:55:02 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "math.h"

int	s21_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

long double	s21_fabs(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

long double	s21_acos(double x)
{
	if (x > 1 || x < -1)
		printf("%s", "nan");
	return (x);
}

long double	s21_asin(double x)
{
	if (x > 1 || x < -1)
		printf("%s", "nan");
	return (x);
}

long double	s21_sqrt(double x)
{
	long double n;

	n = x;
	while ((s21_fabs(x - n * n) > 1e-12))
		n = 0.5 * (n + (x / n));
	return (n);
}

// Нулевая степень
// Отрицательная степень
// Дробь
long double	s21_pow(double base, double exp) 
{
	long double x;
	int 		i;

	i = 1;
	x = base;
	while (i < exp)
	{
		x = x * base;
		i++;
	}
	return (x);
}


int	main(void)
{
	int	i;
	long double k;

	k = 25;
	i = 10030;
	//printf("%d", s21_abs (i));
	// printf("%f", s21_acos (k));
	// printf("%f", s21_asin (k));
	// printf("%f", s21_atan (k));
	// printf("%f", s21_ceil (k));
	// printf("%f", s21_cos (k));
	// printf("%f", s21_exp (k));
	// printf("%f", s21_fabs (k));
	// printf("%f", s21_floor (k));
	// printf("%f", s21_fmod (k));
	// printf("%f", s21_log (k));
	printf("%Lf", s21_pow (k, 2));
	// printf("%f", s21_sin (k));
	//printf("%Lf", s21_sqrt (k));
	// printf("%f", s21_tan (k));
	return (0);
}

// #include <math.h>

// int	main(void)
// {
// 	int	i;
// 	long double k;

// 	i = 10030;
// 	k = 3;
	
// 	// printf("%d", abs (i));
// 	// printf("%f", acos (k));
// 	// printf("%f", asin (k));
// 	// printf("%f", atan (k));
// 	// printf("%f", ceil (k));
// 	// printf("%f", cos (k));
// 	// printf("%f", exp (k));
// 	// printf("%f", fabs (k));
// 	// printf("%f", floor (k));
// 	// printf("%f", fmod (k));
// 	// printf("%f", log (k));
// 	// printf("%f", pow (k, 3));
// 	// printf("%f", sin (k));
// 	//  printf("%f", sqrt (k));
// 	// printf("%f", tan (k));
// 	return (0);
// }

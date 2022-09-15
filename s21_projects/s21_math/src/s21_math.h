#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define S21_NAN (__builtin_nanf(""))
#define S21_INFINITY (__builtin_inff())
#define s21_is_nan(x) __builtin_isnan(x)
#define s21_is_inf(x) __builtin_isinf(x)
#define S21_PI 3.14159265358979323846
#define S21_E 2.71828182845904523536

long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_exp(double x);
long double s21_sqrt(double x);
long double s21_log(double y);

#endif  // SRC_S21_MATH_H_

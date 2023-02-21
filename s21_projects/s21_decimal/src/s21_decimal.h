#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _2(bit) (1 << (bit))
#define S21_MAX_UINT 4294967295
#define MAX_BIT (32 * 4)
#define MAX_DECIMAL 79228162514264337593543950335.f
#define MIN_DECIMAL -79228162514264337593543950335.f
// Output codes
enum result_codes {
  OK = 0,
  FALSE = 0,
  INF_OR_TOO_BIG = 1,
  TRUE = 1,
  CONVERTION_ERROR = 1,
  CALCULATION_ERROR = 1,
  MINUS_INF_OR_TOO_SMALL = 2,
  DIV_BY_ZERO = 3
};

typedef union {
  unsigned int ui;
  float fl;
} floatbits;

// Decimal structure
// Supports numbers from -79,228,162,514,264,337,593,543,950,335 to
// +79,228,162,514,264,337,593,543,950,335.

// bits[0], bits[1], and bits[2] contain the low(LOW), middle(MID) and
// senior(SEN) 32 bits of a 96-bit integer, respectively.
// bits[3] contains a scaling factor and a sign, and consists of the following
// parts: Bits 0 to 15, the lowest word, are not used and must be zero. Bits 16
// to 23 must contain an exponent from 0 to 28, which indicates the power of 10
// to divide an integer. Bits 24 through 30 are not used and must be zero. Bit
// 31 contains a sign; 0 means positive and 1 means negative.

typedef struct {
  unsigned int bits[4];
} s21_decimal;

enum decimal_parts { LOW = 0, MID = 1, SEN = 2, SCALE = 3 };

// Arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// Converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Other functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Common
int s21_find_power(s21_decimal value_1);
int CheckBits(s21_decimal num);
int GetBit(s21_decimal value, int bit_num);
void SetBit(s21_decimal *value, int bit_num, int sign);
int GetSign(s21_decimal value);
void SetSign(s21_decimal *value, int sign);
int ShiftLeft(s21_decimal *value);
int ShiftRight(s21_decimal *value);
void InitialiseNumber(s21_decimal *value);
void BankRounding(s21_decimal *value, int count);
void OutputValue(s21_decimal value);
int getBinExp (float num);

#endif  //  SRC_S21_DECIMAL_H_

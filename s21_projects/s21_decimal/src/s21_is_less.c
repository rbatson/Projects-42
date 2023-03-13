#include "s21_decimal.h"

int s21_is_less(s21_decimal decimal_one, s21_decimal decimal_two) {
  int res = S21_FALSE;
  // if (pow_check(decimal_one) != pow_check(decimal_two)) {
  //     shift_dec(&decimal_one, &decimal_two);
  // }
  if (s21_compare(decimal_one, decimal_two) == 1) {
    res = S21_TRUE;
  }

  return res;
}

// Если первое число отрицательное то 1
int s21_check_scale_less(s21_decimal number_1, s21_decimal number_2) {
  int res = 0;
  if (sign_check(number_1) == 1 && sign_check(number_2) == 0) {
    res = S21_TRUE;
  } else if (sign_check(number_1) == 0 && sign_check(number_2) == 1) {
    res = 2;
  }
  return res;
}

int s21_compare(s21_decimal number_1, s21_decimal number_2) {
  int res = 0;
  if (pow_check(number_1) != pow_check(number_2)) {
    shift_dec(&number_1, &number_2);
  }
  // сравниваем и если равно, то 0; если меньше - 1

  if (sign_check(number_1) == 1 && sign_check(number_2) == 1) {
    for (int j = 95; j >= 0; j--) {
      if (take_bit(number_1, j) > take_bit(number_2, j)) {
        res = 1;
        break;
      } else if (take_bit(number_1, j) < take_bit(number_2, j)) {
        res = 2;
        break;
      }
    }
  } else if (sign_check(number_1) == 0 && sign_check(number_2) == 0) {
    for (int i = 95; i >= 0; i--) {
      if (take_bit(number_1, i) < take_bit(number_2, i)) {
        res = 1;
        // printf("%d\n", res);
        break;
      } else if (take_bit(number_1, i) > take_bit(number_2, i)) {
        res = 2;
        break;
      }
    }
  } else {
    res = s21_check_scale_less(number_1, number_2);
  }
  return res;
}

int s21_is_less_big(s21_big_decimal decimal_one, s21_big_decimal decimal_two) {
  int res = S21_FALSE;
  // if (pow_check(decimal_one) != pow_check(decimal_two)) {
  //     shift_dec(&decimal_one, &decimal_two);
  // }
  if (s21_compare_big(decimal_one, decimal_two) == 1) {
    res = S21_TRUE;
  }

  return res;
}

// int s21_check_scale_less_big(s21_big_decimal number_1,
//                              s21_big_decimal number_2) {
//   int res = 0;
//   if (sign_check_big(number_1) == 1 && sign_check_big(number_2) == 0) {
//     res = S21_TRUE;
//   } else if (sign_check_big(number_1) == 0 && sign_check_big(number_2) == 1)
//   {
//     res = 2;
//   }
//   return res;
// }

int s21_compare_big(s21_big_decimal number_1, s21_big_decimal number_2) {
  int res = 0;
  if (pow_check_big(number_1) != pow_check_big(number_2)) {
    shift_big_dec(&number_1, &number_2);
  }
  // сравниваем и если равно, то 0; если меньше - 1

  if (sign_check_big(number_1) == 1 && sign_check_big(number_2) == 1) {
    for (int j = 191; j >= 0; j--) {
      if (take_bit_big(number_1, j) > take_bit_big(number_2, j)) {
        res = 1;
        break;
      } else if (take_bit_big(number_1, j) < take_bit_big(number_2, j)) {
        res = 2;
        break;
      }
    }
  } else if (sign_check_big(number_1) == 0 && sign_check_big(number_2) == 0) {
    for (int i = 191; i >= 0; i--) {
      if (take_bit_big(number_1, i) < take_bit_big(number_2, i)) {
        res = 1;
        // printf("%d\n", res);
        break;
      } else if (take_bit_big(number_1, i) > take_bit_big(number_2, i)) {
        res = 2;
        break;
      }
    }
    //  } else {
    //    res = s21_check_scale_less_big(number_1, number_2);
  }
  return res;
}

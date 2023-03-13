#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - число слишком велико или равно бесконечности
  // 2 - число слишком мало или равно отрицательной бесконечности
  int error = 0;

  if (sign_check(value_1) == sign_check(value_2)) {
    s21_big_decimal v1 = dec_to_big(value_1);
    s21_big_decimal v2 = dec_to_big(value_2);
    s21_big_decimal res;

    add_big(v1, v2, &res);

    error = big_to_dec(res, result);
    if (error != 0) {
      error = sign_check(value_1) ? code_NEG_INF : code_POS_INF;
    }
  } else {
    error = sign_check(value_2) ? s21_sub(value_1, sign_inv(value_2), result)
                                : s21_sub(value_2, sign_inv(value_1), result);
  }
  return error;
}

// Сложение расш. децималов
int add_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  int flag_bit = 0;  // Флаг перехода разряда между битами
                     //  int temp_res = 0;

  zero_big_init(result);
  shift_big_dec(&value_1, &value_2);

  result->bits[6] = last_bits(pow_check_big(value_1), sign_check_big(value_1));
  // sign_copy(value_1, result);
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 32; j++) {
      int temp_res =
          ((value_1.bits[i] >> j) ^ (value_2.bits[i] >> j)) &
          1;  // Результат сложения конкретных битов без переноса разрядов
      temp_res ^= flag_bit;  // Перенос разряда
      if (!flag_bit) {  // Нет никаких переносов разрядов
        if (((temp_res & 1) == 0) &&
            (((value_1.bits[i] >> j) & 1) == 1)) {  // Будет перенос разряда
          flag_bit = 1;
        }
      } else if ((((value_1.bits[i] >> j) & 1) == 1) ||
                 (((value_2.bits[i] >> j) & 1) ==
                  1)) {  // Будет перенос разряда
        flag_bit = 1;
      } else {
        flag_bit = 0;
      }
      result->bits[i] = result->bits[i] ^ (temp_res << j);
    }
  }
  return flag_bit;
}

#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // 0 - OK
  // 1 - число слишком велико или равно бесконечности
  // 2 - число слишком мало или равно отрицательной бесконечности
  int error = 0;
  //  int sign = 0;

  if (sign_check(value_1) == sign_check(value_2)) {
    zero_init(result);
    if (s21_is_greater_or_equal(module(value_1), module(value_2))) {
      // У результата знак такой же, как у value_1, и меняем - на + у values
      int sign = sign_check(value_1);
      value_1 = sign_check(value_1) ? sign_inv(value_1) : value_1;
      value_2 = sign_check(value_2) ? sign_inv(value_2) : value_2;

      // Вычисления
      s21_big_decimal v1 = dec_to_big(value_1);
      s21_big_decimal v2 = dec_to_big(value_2);
      s21_big_decimal res;
      sub_big(v1, v2, &res);
      res.bits[6] = last_bits(pow_check_big(res), sign);

      error = big_to_dec(res, result);
      if (error != 0) {
        error = sign_check_big(res) ? code_NEG_INF : code_POS_INF;
      }
    } else {
      zero_init(result);
      error = s21_sub(value_2, value_1, result);
      *result = sign_inv(*result);
      // if (error != 0) {
      //     error = sign_check(value_2) ? code_POS_INF : code_NEG_INF;
      // } else {
      //     *result = sign_inv(*result);
      // }
    }
  } else {
    value_2 = sign_inv(value_2);
    error = s21_add(value_1, value_2, result);
    // error = error != 0 ? (sign_check(*result) ? code_NEG_INF : code_POS_INF)
    // : 0;
  }
  return error;
}

// Взятие разряда
// void change_bits(s21_decimal *value, int j) {
//  j++;
//  int i = j / 32;
//  while (j < 96 && !((value->bits[i] >> (j - i * 32)) & 1)) {
//    value->bits[i] ^= 1 << (j - i * 32);
//    j++;
//    i = j / 32;
//  }
//  value->bits[i] &= ~(1 << (j - i * 32));
//}

// Почти нормальное вычитание больших децималов (без сравнения знаков и модулей)
int sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  int error = 0;  // На самом деле не нужно, но я пока оставлю
                  //  int temp_res;
  zero_big_init(result);

  // Вычитаем положительные числа и |a| > |b|
  shift_big_dec(&value_1, &value_2);
  // result->bits[6] = last_bits(pow_check_big(value_1),
  // sign_check_big(*result));
  result->bits[6] = last_bits(pow_check_big(value_1), sign_check_big(value_1));
  //  int i = 0;
  for (int j = 0; j < 192; j++) {
    int i = j / 32;
    int temp_res =
        ((value_1.bits[i] >> (j - i * 32)) ^
         (value_2.bits[i] >> (j - i * 32))) &
        1;  // Результат вычитания конкретных битов без переноса разрядов

    if (temp_res && !(value_1.bits[i] >> (j - i * 32) & 1)) {
      change_bits_big(&value_1, j);
    }
    result->bits[i] = result->bits[i] ^ (temp_res << (j - i * 32));
  }
  return error;
}

// Взятие разряда для большого децимала
void change_bits_big(s21_big_decimal *value, int j) {
  j++;
  int i = j / 32;
  while (j < 192 && !((value->bits[i] >> (j - i * 32)) & 1)) {
    value->bits[i] ^= 1 << (j - i * 32);
    j++;
    i = j / 32;
  }
  value->bits[i] &= ~(1 << (j - i * 32));
}

// // Старое вычитание с плохим округлением
// int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//     // 0 - OK
//     // 1 - число слишком велико или равно бесконечности
//     // 2 - число слишком мало или равно отрицательной бесконечности
//     int error = 0;
//     int temp_res = 0;

//     if (sign_check(value_1) == sign_check(value_2)) {
//         zero_init(result);
//         if (s21_is_greater_or_equal(module(value_1), module(value_2))) {
//             // У результата знак такой же + меняем - на + у values
//             sign_copy(value_1, result);
//             value_1 = sign_check(value_1) ? sign_inv(value_1) : value_1;
//             value_2 = sign_check(value_2) ? sign_inv(value_2) : value_2;

//             // Вычисления
//             shift_dec(&value_1, &value_2);
//             result->bits[3] = last_bits(pow_check(value_1),
//             sign_check(*result)); int i = 0; for (int j = 0; j < 96; j++) {
//                 i = j / 32;
//                 temp_res = ((value_1.bits[i] >> (j - i*32)) ^
//                 (value_2.bits[i] >> (j - i*32))) & 1;  // Результат вычитания
//                 конкретных битов без переноса разрядов

//                 if (temp_res && !(value_1.bits[i] >> (j - i*32) & 1)) {
//                     change_bits(&value_1, j);
//                 }
//                 result->bits[i] = result->bits[i] ^ (temp_res << (j - i*32));
//             }
//         } else {
//             zero_init(result);
//             error = s21_sub(value_2, value_1, result);
//             *result = sign_inv(*result);
//         }
//     } else {
//         value_2 = sign_inv(value_2);
//         error = s21_add(value_1, value_2, result);
//         error = error != 0 ? (sign_check(*result) ? code_NEG_INF :
//         code_POS_INF) : 0;
//     }
//     return error;
// }

#include "s21_decimal.h"

// Переводит децимал в расширенный вариант
s21_big_decimal dec_to_big(s21_decimal value) {
  s21_big_decimal res;
  zero_big_init(&res);
  for (int i = 0; i < 3; i++) {
    res.bits[i] = value.bits[i];
  }
  res.bits[6] = value.bits[3];
  return res;
}

// Перевод в децимал с округлением | 0 - все ок, 1 - расш.децимал не помещается
// в обычный
int big_to_dec(s21_big_decimal value1, s21_decimal *value2) {
  int error = 1;
  // s21_decimal res;
  // zero_init(&res);
  s21_big_decimal v1;
  zero_big_init(&v1);
  int exp = pow_check_big(value1);
  for (int p = exp; p >= 0; p--) {
    v1 = bank_p_big(value1, p);
    // print_bits_big(v1);
    if (check_big(v1) == 0 && pow_check_big(v1) < 29) {
      for (int i = 0; i < 3; i++) {
        value2->bits[i] = v1.bits[i];
      }
      value2->bits[3] = v1.bits[6];
      error = 0;
      break;
    }
  }
  // if (error == 0) *value2 = res;

  // if (check_big(value1) == 0) {
  //     for (int i = 0; i < 3; i++) {
  //         res.bits[i] = value1.bits[i];
  //     }
  //     res.bits[3] = value1.bits[6];
  // } else {
  //     error = 1;
  // }
  // if (error == 0) *value2 = res;

  return error;
}

// Проверяет есть ли биты в расширенной части децимала | 0 - ничего нет, 1 -
// есть
int check_big(s21_big_decimal value) {
  return (value.bits[3] == 0 && value.bits[4] == 0 && value.bits[5] == 0) ? 0
                                                                          : 1;
}

// Вывод
int take_bit_big(s21_big_decimal value, int bit) {
  int res;
  int i = bit / 32;
  res = (value.bits[i] >> (bit - i * 32)) & 1;
  return res;
}

// void str_bits_big(s21_big_decimal value, char *str) {
//   for (int i = 0; i < 192; i++) {
//     str[i] = take_bit_big(value, i);
//     // str[i] = take_bit_big(value, 95 - i);
//   }
// }

// void print_bits_big(s21_big_decimal value) {
//   char str[192];
//   str_bits_big(value, str);
//   for (int i = 0; i < 6; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 1; j <= 32; j++) {
//       // printf("%d", str[(5 - i) * 32 + j]);
//       printf("%d", str[(i + 1) * 32 - j]);
//     }
//     printf(" = %-9u", value.bits[i]);
//     // printf("\n");
//     if (i != 5 && i != 2) {
//       printf("\t");
//     } else {
//       // printf("\n\n");
//       printf("\n");
//     }
//   }
//   printf("sign = %u\t pow = %2u\n", sign_check_big(value),
//          pow_check_big(value));
//   // bits[2] - старший бит
//   // bits[1] - средний бит
//   // bits[0] - младший бит
// }

// void print_all_big(s21_big_decimal value1, s21_big_decimal value2,
//                    s21_big_decimal value3) {
//   char str1[192];
//   char str2[192];
//   char str3[192];
//   str_bits_big(value1, str1);
//   str_bits_big(value2, str2);
//   str_bits_big(value3, str3);
//   for (int i = 0; i < 6; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 1; j <= 32; j++) {
//       printf("%d", str1[(1 + i) * 32 - j]);
//     }
//     // printf(" = %d\t\t", value1.bits[i]);
//     printf(" = %-9u\t", value1.bits[i]);
//     if (i == 2) {
//       printf("\n");
//     }
//   }
//   printf("\n");
//   for (int i = 0; i < 6; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 1; j <= 32; j++) {
//       printf("%d", str2[(1 + i) * 32 - j]);
//     }
//     // printf(" = %d\t\t", value2.bits[i]);
//     printf(" = %-9u\t", value2.bits[i]);
//     if (i == 2) {
//       printf("\n");
//     }
//   }
//   printf("\n");
//   for (int i = 0; i < 6; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 1; j <= 32; j++) {
//       printf("%d", str3[(1 + i) * 32 - j]);
//     }
//     // printf(" = %d\t\t", value3.bits[i]);
//     printf(" = %-9u\t", value3.bits[i]);
//     if (i == 2) {
//       printf("\n");
//     }
//   }
//   printf("\n");
//
//   printf("sign = %u\t pow = %2u\n", sign_check_big(value1),
//          pow_check_big(value1));
//   printf("sign = %u\t pow = %2u\n", sign_check_big(value2),
//          pow_check_big(value2));
//   printf("sign = %u\t pow = %2u\n", sign_check_big(value3),
//          pow_check_big(value3));
// }

// Проверка и создание знака и степени
int sign_check_big(s21_big_decimal value) {  // Проверка есть минус или нет
  return (value.bits[6] >> 31) & 1;
}

int pow_check_big(s21_big_decimal value) {  // Возвращает степень
  return (value.bits[6] >> 16) & 255;
}

// Изменения децимала для вычислений
void zero_big_init(s21_big_decimal *value) {  // Зануляем расш. децимал
  for (int i = 0; i < 7; i++) {
    value->bits[i] = 0;
  }
}

// void sign_copy_big(s21_big_decimal value1,
//                    s21_big_decimal *value2) { // Копируем знак (и степень?)
//   value2->bits[6] = last_bits(pow_check_big(*value2),
//   sign_check_big(value1));
// }

// s21_big_decimal
// sign_inv_big(s21_big_decimal value) { // Меняет знак на проивоположный
//   value.bits[6] ^= (1 << 31);
//   return value;
// }

// s21_big_decimal
// module_big(s21_big_decimal value) { // Модуль расш. децимала со степенью
//   s21_big_decimal res = value;
//   // zero_init(&res);
//   // for (int i = 0; i < 3; i++) {
//   //     res.bits[i] = value.bits[i];
//   // }
//   res.bits[6] = last_bits(pow_check_big(value), 0);
//
//   return res;
// }

// Сдвиг запятой
int mul_big_10(s21_big_decimal *value) {
  int error = 0;
  s21_big_decimal v1 = *value, v2 = *value, res = {{0, 0, 0, 0, 0, 0, 0}};
  if (((value->bits[5] >> 29) & 7) == 0) {  // check_mul10
    shift_big_bits(&v1, 3);
    shift_big_bits(&v2, 1);
    error = add_big(v1, v2, &res);
  } else {
    error = 1;
  }
  // print_all(v1, v2, res);
  if (error == 0) {
    res.bits[6] = last_bits(pow_check_big(*value) + 1,
                            sign_check_big(*value));  // !!!!!!!
    *value = res;
  }
  return error;
}

// Округление до нужного знака после запятой
s21_big_decimal bank_p_big(s21_big_decimal value, int p) {
  s21_big_decimal res = value;
  // res.bits[6] = last_bits(pow_check(value) - p, sign_check(value));
  res.bits[6] = last_bits(pow_check_big(value) - p, sign_check_big(value));
  // s21_round(res, &res);
  s21_banking_round_big(res, &res);
  res.bits[6] = last_bits(p, sign_check_big(value));
  return res;
}

// Сдвиг запятой
void shift_big_dec(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int p = abs(pow_check_big(*value_1) - pow_check_big(*value_2));
  int error = 0;
  while (p > 0) {
    if (pow_check_big(*value_1) > pow_check_big(*value_2)) {
      error = mul_big_10(value_2);
    } else if (pow_check_big(*value_1) < pow_check_big(*value_2)) {
      error = mul_big_10(value_1);
    }
    if (error == 0) {
      p--;
    } else {
      break;
    }
  }
  // if (p > 0) {  // условине не будет выполняться никогда
  //     if ((pow_check_big(*value_1) > pow_check_big(*value_2))) {
  //         *value_1 = bank_p(*value_1, pow_check_big(*value_2));
  //     } else {
  //         *value_2 = bank_p(*value_2, pow_check_big(*value_1));
  //     }
  // }
}

// Сколько битов занято в расш. децимале
int num_bits_big_dec(s21_big_decimal value) {
  int j;
  for (j = 191; j >= 0; j--) {
    int i = j / 32;
    int k = j - i * 32;
    // printf("k = %d\n", k);
    // printf("(value.bits[i] >> k) & 1 = %d\n", (value.bits[i] >> k) & 1);
    if ((value.bits[i] >> k) & 1) {
      break;
    }
  }
  return j + 1;
}

// Сдвигаем расш. децимал на j позиций
int shift_big_bits(s21_big_decimal *value, int j) {
  int res = 1;
  //  int temp = 0;
  if (j <= 192 - num_bits_big_dec(*value)) {
    for (int k = 0; k < j; k++) {
      int temp = 0;
      for (int i = 0; i < 6; i++) {
        if (temp) {
          temp = value->bits[i] >> 31;
          value->bits[i] = ((value->bits[i] & ~(1 << 31)) << 1) ^ 1;
        } else {
          temp = value->bits[i] >> 31;
          value->bits[i] = (value->bits[i] & ~(1 << 31)) << 1;
        }
      }
    }
  } else {
    res = 0;
  }
  return res;
}

// Умножение часла на 10, степень и знак не меняются | Для деления
int mul_big_dec_10(s21_big_decimal *value) {
  int error = 0;
  s21_big_decimal v1 = *value, v2 = *value, res = {{0, 0, 0, 0, 0, 0, 0}};
  if (((value->bits[5] >> 29) & 7) == 0) {  // check_mul10
    shift_big_bits(&v1, 3);
    shift_big_bits(&v2, 1);
    error = add_big(v1, v2, &res);
  } else {
    error = 1;
  }
  // print_all(v1, v2, res);
  if (error == 0) {
    res.bits[6] =
        last_bits(pow_check_big(*value), sign_check_big(*value));  // !!!!!!!
    *value = res;
  }
  return error;
}

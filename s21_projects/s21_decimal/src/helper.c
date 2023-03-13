#include "s21_decimal.h"

// Вывод
int take_bit(s21_decimal value, int bit) {
  int res;
  int i = bit / 32;
  res = (value.bits[i] >> (bit - i * 32)) & 1;
  return res;
}

// void str_bits(s21_decimal value, char *str) {
//   for (int i = 0; i < 96; i++) {
//     str[i] = take_bit(value, 95 - i);
//   }
// }

// void print_bits(s21_decimal value) {
//   char str[96];
//   str_bits(value, str);
//   for (int i = 0; i < 3; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 0; j < 32; j++) {
//       printf("%d", str[(2 - i) * 32 + j]);
//     }
//     printf(" = %-9u", value.bits[i]);
//     // printf("\n");
//     if (i != 2) {
//       printf("\t");
//     } else {
//       // printf("\n\n");
//       printf("\n");
//     }
//   }

// printf("sign = %u\t pow = %2u\n", sign_check(value), pow_check(value));

// bits[2] - старший бит
// bits[1] - средний бит
// bits[0] - младший бит
//}

// void print_all(s21_decimal value1, s21_decimal value2, s21_decimal value3) {
//   char str1[96];
//   char str2[96];
//   char str3[96];
//   str_bits(value1, str1);
//   str_bits(value2, str2);
//   str_bits(value3, str3);
//   for (int i = 0; i < 3; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 0; j < 32; j++) {
//       printf("%d", str1[(2 - i) * 32 + j]);
//     }
//     // printf(" = %d\t\t", value1.bits[i]);
//     printf(" = %-9u\t", value1.bits[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < 3; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 0; j < 32; j++) {
//       printf("%d", str2[(2 - i) * 32 + j]);
//     }
//     // printf(" = %d\t\t", value2.bits[i]);
//     printf(" = %-9u\t", value2.bits[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < 3; i++) {
//     printf("bits[%d] = ", i);
//     for (int j = 0; j < 32; j++) {
//       printf("%d", str3[(2 - i) * 32 + j]);
//     }
//     // printf(" = %d\t\t", value3.bits[i]);
//     printf(" = %-9u\t", value3.bits[i]);
//   }
//   printf("\n");
//
//   printf("sign = %u\t pow = %2u\n", sign_check(value1), pow_check(value1));
//   printf("sign = %u\t pow = %2u\n", sign_check(value2), pow_check(value2));
//   printf("sign = %u\t pow = %2u\n", sign_check(value3), pow_check(value3));
// }

// Проверка и создание знака и степени
int sign_check(s21_decimal value) {  // Проверка есть минус или нет
  return (value.bits[3] >> 31) & 1;
}

int pow_check(s21_decimal value) {  // Возвращает степень
  return (value.bits[3] >> 16) & 255;
}

int last_bits(int pow,
              int sign) {  // Возвращает число для последнего бита массива
  return (pow << 16) ^ (sign << 31);
}

// Изменения децимала для вычислений
void zero_init(s21_decimal *value) {  // Зануляем децимал
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

// void sign_copy(s21_decimal value1, s21_decimal *value2) {
//   value2->bits[3] = last_bits(pow_check(*value2), sign_check(value1));
// }

s21_decimal sign_inv(s21_decimal value) {  // Меняет знак на проивоположный
  value.bits[3] ^= (1 << 31);
  return value;
}

s21_decimal module(s21_decimal value) {  // Модуль децимала со степенью
  s21_decimal res = value;
  // zero_init(&res);
  // for (int i = 0; i < 3; i++) {
  //     res.bits[i] = value.bits[i];
  // }
  res.bits[3] = last_bits(pow_check(value), 0);

  return res;
}

// Сдвиг запятой
int mul_10(s21_decimal *value) {
  int error = 0;
  s21_decimal v1 = *value, v2 = *value, res = {{0, 0, 0, 0}};
  if (((value->bits[2] >> 29) & 7) == 0) {  // check_mul10
    shift_bits(&v1, 3);
    shift_bits(&v2, 1);
    error = s21_add(v1, v2, &res);
  } else {
    error = 1;
  }
  // print_all(v1, v2, res);
  if (error == 0) {
    res.bits[3] =
        last_bits(pow_check(*value) + 1, sign_check(*value));  // !!!!!!!
    *value = res;
  }
  return error;
}

// Округление до нужного знака после запятой
s21_decimal bank_p(s21_decimal value, int p) {
  s21_decimal res = value;
  res.bits[3] = last_bits(pow_check(value) - p, sign_check(value));
  // s21_round(res, &res);
  s21_banking_round(res, &res);
  res.bits[3] = last_bits(p, sign_check(value));
  return res;
}

// Сдвиг запятой
void shift_dec(s21_decimal *value_1, s21_decimal *value_2) {
  int p = abs(pow_check(*value_1) - pow_check(*value_2));
  int error = 0;
  while (p > 0) {
    if (pow_check(*value_1) > pow_check(*value_2)) {
      error = mul_10(value_2);
    } else if (pow_check(*value_1) < pow_check(*value_2)) {
      error = mul_10(value_1);
    }
    if (error == 0) {
      p--;
    } else {
      break;
    }
  }
  if (p > 0) {
    if ((pow_check(*value_1) > pow_check(*value_2))) {
      *value_1 = bank_p(*value_1, pow_check(*value_2));
    } else {
      *value_2 = bank_p(*value_2, pow_check(*value_1));
    }
  }
}

// Сколько битов занято в децимале
int num_bits_dec(s21_decimal value) {
  int j;
  for (j = 95; j >= 0; j--) {
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

// Сколько битов занято в числе
// int num_bits_int(int value) {
//  int j;
//  for (j = 31; j >= 0; j--) {
//    if (value & (1 << j)) {
//      break;
//    }
//  }
//  return j + 1;
//}

// Сдвигаем децимал на j позиций
int shift_bits(s21_decimal *value, int j) {
  int res = 1;
  //  int temp = 0;
  if (j <= 96 - num_bits_dec(*value)) {
    for (int k = 0; k < j; k++) {
      int temp = 0;
      for (int i = 0; i < 3; i++) {
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

// Проверяет только сдвиг на 3 бита!!! Нужно еще учитывать сложение
// int check_mul10(s21_decimal value, int p) {  // Проверяет можно ли умножать
// на 10
//     return !((value.bits[2] >> (32 - p)) & 7) ? 1 : 0;
// }

// s21_decimal mul_10(s21_decimal value) {
//     s21_decimal v1 = value, v2 = value, res = {{0, 0, 0, 0}};
//     if (((value.bits[2] >> 29) & 7) == 0) {  // check_mul10
//         shift_bits(&v1, 3);
//         shift_bits(&v2, 1);
//     }
//     s21_add(v1, v2, &res);
//     // print_all(v1, v2, res);
//     res.bits[3] = last_bits(pow_check(value)+1, sign_check(value));  //
//     !!!!!!! return res;
// }

// Сдвиг запятой
// void shift_dec(s21_decimal *value_1, s21_decimal *value_2) {
//     int p = abs(pow_check(*value_1) - pow_check(*value_2));
//     int error = 0;
//     if (pow_check(*value_1) > pow_check(*value_2)) {
//         if (check_mul10(*value_2, p)) {
//             for (int i = 0; i < p; i++) {
//                 *value_2 = mul_10(*value_2);
//             }
//         } else {  // Деление на 10 | округляем value_1
//             *value_1 = bank_p(*value_1, pow_check(*value_2));
//         }
//     } else if (pow_check(*value_1) < pow_check(*value_2)) {
//         if (check_mul10(*value_1, p)) {
//             for (int i = 0; i < p; i++) {
//                 *value_1 = mul_10(*value_1);
//             }
//         } else {  // Деление на 10
//             *value_2 = bank_p(*value_2, pow_check(*value_1));
//         }
//     }
//     // if (pow_check(*value_1) > pow_check(*value_2)) {
//     //     while (p > 0) {
//     //         error = mul_10(value_2);
//     //         if (error == 0) {
//     //             p--;
//     //         } else {
//     //             break;
//     //         }
//     //     }
//     //     if (p > 0) {
//     //         *value_1 = bank_p(*value_1, pow_check(*value_2));
//     //     }
//     // } else if (pow_check(*value_1) < pow_check(*value_2)) {
//     //     while (p > 0) {
//     //         error = mul_10(value_1);
//     //         if (error == 0) {
//     //             p--;
//     //         } else {
//     //             break;
//     //         }
//     //     }
//     //     if (p > 0) {
//     //         *value_1 = bank_p(*value_2, pow_check(*value_1));
//     //     }
//     // }
// }

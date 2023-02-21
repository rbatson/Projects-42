#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2){
    int res = 1;
    for (int i = 0; i < MAX_BIT; i++){
        if (GetBit(value_1, i) != GetBit(value_2, i)){
            res = 0;
            break;
        }
    }
    return res;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2){
    return !s21_is_equal(value_1, value_2);
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2){
    int res = 0;
    int k = 95;
    for (int i = 95; i >= 0 && k >= 0; i--, k--){
        if ((GetSign(value_1) == 1 && GetSign(value_2) == 0) \
        || (GetBit(value_1, i) == 0 && GetBit(value_2, k) == 1))
            res = 1;
        if (s21_find_power(value_1) > s21_find_power(value_2))
            res = 1;
    }
    return res;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2){
    int res = 0;
    int k = 95;
    for (int i = 95; i >= 0 && k >= 0; i--, k--){
        if ((GetSign(value_1) == 0 && GetSign(value_2) == 1) \
        || (GetBit(value_1, i) == 1 && GetBit(value_2, k) == 0))
            res = 1;
        if (s21_find_power(value_1) < s21_find_power(value_2))
            res = 1;
    }
    return res;
}

int s21_find_power(s21_decimal value_1)
{
    int res = 0;
    int k = 119;
    s21_decimal result = {0,0,0,0};
    for (int i = 0; i < 8; i++)
    {
        SetBit(&result, i, GetBit(value_1, k));
        k--;
    }
    return s21_from_decimal_to_int(result, &res);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2)
{
    int res = 0;
    if (s21_is_less(value_1, value_2) == 1)
        res = 1;
    else if (s21_is_equal(value_1, value_2) == 1)
        res = 1;
    return res;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2)
{
    int res = 0;
    if (s21_is_greater(value_1, value_2) == 1)
        res = 1;
    else if (s21_is_equal(value_1, value_2) == 1)
        res = 1;
    return res;
}
#include "s21_decimal.h"

//------------------------------------------------------------ int --> decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    InitialiseNumber(dst);
    int flag_result = 1;
    if (src != INFINITY && src != -INFINITY) {
        if (src < 0) {
            SetSign(dst, 1);
            dst->bits[LOW] = -src; 
        } else {
            SetSign(dst, 0);
            dst->bits[LOW] = src;
        }
    } else {
        flag_result = 0;
    }

    return (flag_result) ? OK : CONVERTION_ERROR;
}


//------------------------------------------------------------ decimal --> int
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int flag_result = 1;
    if (dst) {
        int sign = (GetSign(src)) ? -1 : 1;
        int res = (int)(src.bits[LOW] * pow(10, (s21_find_power(src)*-1)));
        *dst = res * sign;
    } else {
        flag_result = 0;
    }
    if (src.bits[MID] != 0 || src.bits[SEN] != 0 ) {
        flag_result = 0;
    }
    return (flag_result) ? OK : CONVERTION_ERROR;
}


//---------------------------------------------------------- float --> decimal

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int flag_result = OK;
    if (src > MAX_DECIMAL || src < MIN_DECIMAL || isnan(src) || src == INFINITY
    || src == -INFINITY) {
        flag_result = CONVERTION_ERROR;
    } else if (src < 1e-28) {
        src = 0;
        InitialiseNumber(dst);
        flag_result = CONVERTION_ERROR;
    } else {
        int sign = 0;
        if (src < 0) sign = 1, src *= -1;
        int binaryexp = getBinExp(src);
        if (binaryexp > 95) {
            flag_result = CONVERTION_ERROR;
        } else {
            unsigned int count = 0;
            for (; !((int)src); src *= 10, count++) {}
            for (; src / 1000000 < 1; src *= 10, count++) {}
            binaryexp = getBinExp(src);

            if (binaryexp < -94 || count > 28) {
                flag_result = CONVERTION_ERROR;
            } else {
                floatbits a = {.fl = src};
                SetBit(dst, binaryexp, 1); // Устанавливаем невидимую 1
                unsigned int mask = 0x400000;
                for (int i = binaryexp - 1; i >= 0 && mask; i--, mask >>= 1)
                    if (mask & a.ui) SetBit(dst, i, 1);
                dst->bits[SCALE] = count << 16;
                
                
                SetSign(dst, sign);
            }
        }
    }
    return flag_result;
}


//---------------------------------------------------------- decimal --> float
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int flag_result = 1;
    double res = 0, tmp=1;
    if (dst) {
        *dst = 0;
        for(int i = 0; i < 96; i++) {
            if (GetBit(src, i)) {
                res += tmp;
            }
            tmp *= 2;
        }
        for (int k = 0; k < s21_find_power(src); k++) {
            res /= 10;
        }
        if (GetSign(src)) {
            res *= -1; 
        }
        *dst = res;
    } else {
        flag_result = 0;
    }
    return (flag_result) ? 1 : 0;
}


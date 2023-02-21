#include "s21_decimal.h"

int CheckBits(s21_decimal num) {
    int res = 0;
    int count =  0;
    for(int i=32; i < 127; i++) {
        if (GetBit(num, i) != 0) {
            res = 1;
            i = 128;
        }
        count++;
    }
    return res;
}

int GetBit(s21_decimal value, int bit_num) {
  unsigned int mask = 1 << (bit_num % 32);
  return !!(value.bits[bit_num / 32] & mask);
}

void SetBit(s21_decimal* value, int bit_num, int bit) {
  unsigned int mask = 1 << (bit_num % 32);
  if (bit == 0) {
    value->bits[bit_num / 32] &= ~mask;
  } else {
    value->bits[bit_num / 32] |= mask;
  }
}

int GetSign(s21_decimal value) {
  int sign;
  if ((value.bits[3] & (1 << 31)) == 0) {
    sign = 0;
  } else {
    sign = 1;
  }
  return sign;
}

void SetSign(s21_decimal* value, int sign) {
  if (sign == 0) {
    value->bits[3] = value->bits[3] & ~(1 << 31);
  } else {
    value->bits[3] = value->bits[3] | (1 << 31);
  }
}

int ShiftLeft(s21_decimal* value) {
  int overflow = GetBit(*value, 95);
  for (int i = 95; i >= 0; i--) {
    if (i != 0) {
      SetBit(value, i, GetBit(*value, i - 1));
    } else {
      SetBit(value, i, 0);
    }
  }
  return overflow;
}

int ShiftRight(s21_decimal* value) {
  int overflow = GetBit(*value, 1);
  for (int i = 0; i < 96; i++) {
    if (i != 95) {
      SetBit(value, i, GetBit(*value, i + 1));
    } else {
      SetBit(value, i, 0);
    }
  }
  return overflow;
}

void InitialiseNumber(s21_decimal* value) {
  for (int i = 0; i < 128; i++) {
    SetBit(value, i, 0);
  }
}

int getBinExp (float num) {
    unsigned int fbits = *((unsigned int*)&num);
    int index = 0, result = 0;
    for (int i=23; i < 31; i++) {
        unsigned int mask = 1 << i;
        result += (!!(fbits & mask)) * pow(2, index);
        index++;
    }
    return result-127;
}

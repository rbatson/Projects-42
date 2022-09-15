#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? x * -1 : x; }

long double s21_fabs(double x) {
  return x < 0.0 ? (long double)x * -1.0 : (long double)x;
}

long double s21_atan(double x) {
  long double res = 0.0;
  double big_x = x, mig;

  if ((x / 1.0) == x) {
    if (x > 1.0) big_x = 1.0 / x;
    if (x < -1.0) big_x = 1.0 / x * -1.0;
    mig = big_x;
    for (int i = 1; i < 500000; ++i) {
      res += mig;
      mig *= -((2.0 * i - 1) * big_x * big_x / (2.0 * (double)i + 1.0));
    }
    if (x > 1.0) res = S21_PI / 2 - res;
    if (x < -1.0) res = (S21_PI / 2 - res) * -1;
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_acos(double x) {
  long double res = 0.0;

  if (x >= -1.0 && x < 0.0) {
    res = S21_PI - s21_asin(s21_pow(1.0 - x * x, 0.5));
  } else if (x >= 0.0 && x <= 1.0) {
    res = s21_asin(s21_pow(1.0 - x * x, 0.5));
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_asin(double x) {
  long double res = 0.0;

  if (x >= -1.0 && x <= 1.0) {
    res = s21_atan(x / s21_sqrt(1.0 - x * x));
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long long int sum;
  long double res, def;

  if (y == 0.0 || s21_is_inf(x)) {
    def = S21_NAN;
  } else if (s21_is_inf(y)) {
    def = x;
  } else {
    sum = (long long int)(x / y);
    res = y * (long double)sum;
    def = x - res;
    if (x < 0.0 && res < x) {
      def = y;
    } else if (x >= 0.0 && res > x) {
      def = y;
    }
  }
  return def;
}

long double s21_pow(double base, double exp) {
  long double res;

  if (base == 1.0 || exp == 0.0) {
    res = 1.0;
  } else if (base < 0.0 && s21_fmod(exp, 1.0) != 0) {
    res = -S21_NAN;
  } else {
    res = s21_exp(exp * s21_log(s21_fabs(base)));
  }
  if (base < 0.0 && s21_fmod(exp, 2.0) != 0.0) {
    res *= -1;
  }
  if (base == 0.0 && exp < 0.0) res = S21_INFINITY;
  return res;
}

long double s21_floor(double x) {
  long double res = x;

  res = (long long)x;
  if (x - res >= 1.0 || x - res <= -1.0) {
    res = x;
  } else {
    if (res > x) res -= 1.0;
  }
  return (s21_is_nan(x) || s21_is_inf(x)) ? x : res;
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  int n = 1;
  long double temp = x;
  long double result = 0;

  while (n < 10000) {
    result += temp;
    n += 2;
    temp *= -(x * x) / ((n - 1) * n);
  }
  return result;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  int n = 0;
  long double temp = 1;
  long double result = 0;

  while (n < 10000) {
    result += temp;
    n += 2;
    temp *= -(x * x) / ((n - 1) * n);
  }
  return result;
}

long double s21_tan(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  return s21_sin(x) / s21_cos(x);
}

long double s21_ceil(double x) {
  long double res = x;

  res = (long long)x;
  if (x - res >= 1.0 || x - res <= -1.0) {
    res = x;
  } else {
    if (res < x) res += 1.0;
  }
  return (s21_is_nan(x) || s21_is_inf(x)) ? x : res;
}

long double s21_exp(double x) {
  int minus = 0;
  long double sum = 1.0;
  long int n = 1;

  if (x < 0) {
    x *= -1;
    minus = 1;
  }
  long double x1 = x;
  long double x2 = x * x / 2;
  do {
    sum += x1 + x2;
    n++;
    x1 *= x * x / ((2 * n - 1) * (2 * n - 2));
    x2 *= x * x / ((2 * n - 1) * 2 * n);
  } while (n < 100000);
  if (minus) sum = 1 / sum;
  return sum;
}

long double s21_sqrt(double x) {
  if (s21_is_nan(x) || s21_is_inf(x)) {
    return x;
  }
  if (x < 0) {
    return S21_NAN;
  }

  double start = 0.0, mid, last = x;
  if (x < 1.0) {
    last = 1.0;
  }
  mid = (start + last) / 2.0;
  do {
    if (mid * mid > x) {
      last = mid;
    } else {
      start = mid;
    }
    mid = (start + last) / 2.0;
  } while ((mid - start) > 0.00000001);
  return mid;
}

long double s21_log(double x) {
  int ex_pow = 0;
  double result = 0;
  double compare = 0;

  if (s21_is_inf(x) || s21_is_nan(x)) {
    result = x;
  } else if (x == 0.0) {
    result = -S21_INFINITY;
  } else if (x < 0.0) {
    result = S21_NAN;
  } else if (x == 1.0) {
    result = 0.0;
  } else {
    for (; x >= S21_E; x /= S21_E, ex_pow++) continue;
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return (result + ex_pow);
}

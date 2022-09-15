#!bin/bash

echo "#include <stdio.h>" >> atest.check
echo "#include <stdlib.h>" >> atest.check
echo "#include <math.h>" >> atest.check
echo -e "#include \"s21_math.h\"\n" >> atest.check


echo -e "#tcase abs\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test abs_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking ABS function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: abs_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_int_eq(abs(-100 + $n), s21_abs(-100 + $n));\n" >> atest.check
done


echo -e "#tcase acos\n" >> atest.check
for ((n = 1; n <= 20; ++n))
do
    echo "#test acos_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking ACOS function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: acos_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(acos(-0.1 + ($n * 0.01)), s21_acos(-0.1 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 20; ++n))
do
    echo "#test acos_2_$n" >> atest.check
    echo "    printf(\"Test number: acos_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(acos(-0.01 + ($n * 0.001)), s21_acos(-0.01 + ($n * 0.001)), 1e-06);\n" >> atest.check
done
echo "#test acos_3_nan" >> atest.check
echo "    printf(\"Test number: acos_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(acos(NAN)), isnan(s21_acos(NAN)), 1e-06);\n" >> atest.check
echo "#test acos_3_inf" >> atest.check
echo "    printf(\"Test number: acos_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(acos(INFINITY)), isinf(s21_acos(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase asin\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test asin_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking ASIN function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: asin_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(asin(-1.0 + ($n * 0.01)), s21_asin(-1.0 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test asin_2_$n" >> atest.check
    echo "    printf(\"Test number: asin_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(asin(-0.1 + ($n * 0.001)), s21_asin(-0.1 + ($n * 0.001)), 1e-06);\n" >> atest.check
done
echo "#test asin_3_nan" >> atest.check
echo "    printf(\"Test number: asin_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(asin(NAN)), isnan(s21_asin(NAN)), 1e-06);\n" >> atest.check
echo "#test asin_3_inf" >> atest.check
echo "    printf(\"Test number: asin_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(asin(INFINITY)), isinf(s21_asin(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase atan\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test atan_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking ATAN function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: atan_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(atan(-100.0 + $n.0), s21_atan(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test atan_2_$n" >> atest.check
    echo "    printf(\"Test number: atan_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(atan(-1.003 + ($n * 0.01)), s21_atan(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test atan_3_nan" >> atest.check
echo "    printf(\"Test number: atan_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(atan(NAN)), isnan(s21_atan(NAN)), 1e-06);\n" >> atest.check
echo "#test atan_3_inf" >> atest.check
echo "    printf(\"Test number: acos_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(atan(INFINITY)), isinf(s21_atan(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase ceil\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test ceil_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking CEIL function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: ceil_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(ceil(-100.0 + $n.0), s21_ceil(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test ceil_2_$n" >> atest.check
    echo "    printf(\"Test number: ceil_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(ceil(-1.003 + ($n * 0.01)), s21_ceil(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test ceil_3_nan" >> atest.check
echo "    printf(\"Test number: ceil_3_nan$n\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(ceil(NAN)), isnan(s21_ceil(NAN)), 1e-06);\n" >> atest.check
echo "#test ceil_3_inf" >> atest.check
echo "    printf(\"Test number: ceil_3_inf$n\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(ceil(INFINITY)), isinf(s21_ceil(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase cos\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test cos_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking COS function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: cos_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(cos(-100.0 + $n.0), s21_cos(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test cos_2_$n" >> atest.check
    echo "    printf(\"Test number: cos_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(cos(-1.003 + ($n * 0.01)), s21_cos(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test cos_3_nan" >> atest.check
echo "    printf(\"Test number: cos_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(cos(NAN)), isnan(s21_cos(NAN)), 1e-06);\n" >> atest.check
echo "#test cos_3_inf" >> atest.check
echo "    printf(\"Test number: cos_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(cos(INFINITY)), isinf(s21_cos(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase exp\n" >> atest.check
for ((n = 1; n <= 40; ++n))
do
    echo "#test exp_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking EXP function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: exp_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(exp(-20.0 + $n.0), s21_exp(-20.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test exp_2_$n" >> atest.check
    echo "    printf(\"Test number: exp_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(exp(-1.003 + ($n * 0.01)), s21_exp(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test exp_3_nan" >> atest.check
echo "    printf(\"Test number: exp_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(exp(NAN)), isnan(s21_exp(NAN)), 1e-06);\n" >> atest.check
echo "#test exp_3_inf" >> atest.check
echo "    printf(\"Test number: exp_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(exp(INFINITY)), isinf(s21_exp(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase fabs\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test fabs_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking FABS function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: fabs_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(fabs(-100.0 + $n.0), s21_fabs(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test fabs_2_$n" >> atest.check
    echo "    printf(\"Test number: fabs_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(fabs(-1.003 + ($n * 0.01)), s21_fabs(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test fabs_3_nan" >> atest.check
echo "    printf(\"Test number: fabs_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(fabs(NAN)), isnan(s21_fabs(NAN)), 1e-06);\n" >> atest.check
echo "#test fabs_3_inf" >> atest.check
echo "    printf(\"Test number: fabs_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(fabs(INFINITY)), isinf(s21_fabs(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase floor\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test floor_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking FLOOR function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: floor_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(floor(-100.0 + $n.0), s21_floor(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test floor_2_$n" >> atest.check
    echo "    printf(\"Test number: floor_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(floor(-1.003 + ($n * 0.01)), s21_floor(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test floor_3_nan" >> atest.check
echo "    printf(\"Test number: floor_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(floor(NAN)), isnan(s21_floor(NAN)), 1e-06);\n" >> atest.check
echo "#test floor_3_inf" >> atest.check
echo "    printf(\"Test number: floor_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(floor(INFINITY)), isinf(s21_floor(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase fmod\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    if ((n == 100))
    then
        ((n = n + 1))
    fi
    echo "#test fmod_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking FMOD function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: fmod_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(fmod(-100.0 + $n.0, -10.0 + $n * 0.1), s21_fmod(-100.0 + $n.0, -10.0 + $n * 0.1), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test fmod_2_$n" >> atest.check
    echo "    printf(\"Test number: fmod_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(fmod(-1.003 + ($n * 0.01), -0.1003 + ($n * 0.001)), s21_fmod(-1.003 + ($n * 0.01), -0.1003 + ($n * 0.001)), 1e-06);\n" >> atest.check
done
echo "#test fmod_3_nan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(fmod(NAN, NAN)), isnan(s21_fmod(NAN, NAN)), 1e-06);\n" >> atest.check
echo "#test fmod_3_inf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(fmod(INFINITY, INFINITY)), isnan(s21_fmod(INFINITY, INFINITY)), 1e-06);\n" >> atest.check
echo "#test fmod_4_naninf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(fmod(NAN, INFINITY)), isinf(s21_fmod(NAN, INFINITY)), 1e-06);\n" >> atest.check
echo "#test fmod_4_infnan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(fmod(INFINITY, NAN)), isnan(s21_fmod(INFINITY, NAN)), 1e-06);\n" >> atest.check
echo "#test fmod_5_nannum" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(fmod(NAN, 6)), isnan(s21_fmod(NAN, 6)), 1e-06);\n" >> atest.check
echo "#test fmod_5_numnan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(fmod(7, NAN)), isinf(s21_fmod(7, NAN)), 1e-06);\n" >> atest.check
echo "#test fmod_5_numinf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(fmod(5, INFINITY)), isinf(s21_fmod(5, INFINITY)), 1e-06);\n" >> atest.check
echo "#test fmod_5_infnum" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(fmod(INFINITY, 3)), isnan(s21_fmod(INFINITY, 3)), 1e-06);\n" >> atest.check


echo -e "#tcase log\n" >> atest.check
for ((n = 1; n <= 20; ++n))
do
    echo "#test log_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking LOG function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: log_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(log(0.0 + $n.0), s21_log(0.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 20; ++n))
do
    echo "#test log_2_$n" >> atest.check
    echo "    printf(\"Test number: log_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(log(0.003 + ($n * 0.01)), s21_log(0.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test log_3_nan" >> atest.check
echo "    printf(\"Test number: log_3_nan\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(log(NAN)), isnan(s21_log(NAN)), 1e-06);\n" >> atest.check
echo "#test log_3_inf" >> atest.check
echo "    printf(\"Test number: log_3_inf\\n\");" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(log(INFINITY)), isinf(s21_log(INFINITY)), 1e-06);\n" >> atest.check


echo -e "#tcase pow\n" >> atest.check
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking POW function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: pow_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(0.1 + $n.0, -1.0), s21_pow(0.1 + $n.0, -1.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_2_$n" >> atest.check
    echo "    printf(\"Test number: pow_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(0.1 + $n.0, -3.0), s21_pow(0.1 + $n.0, -3.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_3_$n" >> atest.check
    echo "    printf(\"Test number: pow_3_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(-25.0 + $n.0, 2.0), s21_pow(-25.0 + $n.0, 2.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_4_$n" >> atest.check
    echo "    printf(\"Test number: pow_4_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(-25.0 + $n.0, 4.0), s21_pow(-25.0 + $n.0, 4.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_5_$n" >> atest.check
    echo "    printf(\"Test number: pow_5_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(-25.0 + $n.0, 0.0), s21_pow(-25.0 + $n.0, 0.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_6_$n" >> atest.check
    echo "    printf(\"Test number: pow_6_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(0.01 + $n.0, 0.5), s21_pow(0.01 + $n.0, 0.5), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 10; ++n))
do
    echo "#test pow_7_$n" >> atest.check
    echo "    printf(\"Test number: pow_7_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(pow(0.01 + $n.0, 1.2), s21_pow(0.01 + $n.0, 1.2), 1e-06);\n" >> atest.check
done
echo "#test pow_3_nan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(pow(NAN, NAN)), isnan(s21_pow(NAN, NAN)), 1e-06);\n" >> atest.check
echo "#test pow_3_inf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(pow(INFINITY, INFINITY)), isnan(s21_pow(INFINITY, INFINITY)), 1e-06);\n" >> atest.check
echo "#test pow_4_naninf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(pow(NAN, INFINITY)), isinf(s21_pow(NAN, INFINITY)), 1e-06);\n" >> atest.check
echo "#test pow_4_infnan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(pow(INFINITY, NAN)), isnan(s21_pow(INFINITY, NAN)), 1e-06);\n" >> atest.check
echo "#test pow_5_nannum" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(pow(NAN, 6)), isnan(s21_pow(NAN, 6)), 1e-06);\n" >> atest.check
echo "#test pow_5_numnan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(pow(7, NAN)), isinf(s21_pow(7, NAN)), 1e-06);\n" >> atest.check
echo "#test pow_5_numinf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(pow(5, INFINITY)), isinf(s21_pow(5, INFINITY)), 1e-06);\n" >> atest.check
echo "#test pow_5_infnum" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(pow(INFINITY, 3)), isnan(s21_pow(INFINITY, 3)), 1e-06);\n" >> atest.check

echo -e "#tcase sin\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test sin_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking SIN function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: sin_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(sin(-100.0 + $n.0), s21_sin(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test sin_2_$n" >> atest.check
    echo "    printf(\"Test number: sin_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(sin(-1.003 + ($n * 0.01)), s21_sin(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test sin_3_nan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(sin(NAN)), isnan(s21_sin(NAN)), 1e-06);\n" >> atest.check
echo "#test sin_3_inf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(sin(INFINITY)), isinf(s21_sin(INFINITY)), 1e-06);\n" >> atest.check

echo -e "#tcase sqrt\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test sqrt_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking SQRT function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: sqrt_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(sqrt(0.0 + $n.0), s21_sqrt(0.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test sqrt_2_$n" >> atest.check
    echo "    printf(\"Test number: sqrt_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(sqrt(1.003 + ($n * 0.01)), s21_sqrt(1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test sqrt_3_nan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(sqrt(NAN)), isnan(s21_sqrt(NAN)), 1e-06);\n" >> atest.check
echo "#test sqrt_3_inf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(sqrt(INFINITY)), isinf(s21_sqrt(INFINITY)), 1e-06);\n" >> atest.check

echo -e "#tcase tan\n" >> atest.check
for ((n = 1; n <= 200; ++n))
do
    echo "#test tan_1_$n" >> atest.check
    if ((n == 1))
    then
        echo "    printf(\"Checking TAN function...\\n\");" >> atest.check
    fi
    echo "    printf(\"Test number: tan_1_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(tan(-100.0 + $n.0), s21_tan(-100.0 + $n.0), 1e-06);\n" >> atest.check
done
for ((n = 1; n <= 200; ++n))
do
    echo "#test tan_2_$n" >> atest.check
    echo "    printf(\"Test number: tan_2_$n\\n\");" >> atest.check
    echo -e "    ck_assert_double_eq_tol(tan(-1.003 + ($n * 0.01)), s21_tan(-1.003 + ($n * 0.01)), 1e-06);\n" >> atest.check
done
echo "#test tan_3_nan" >> atest.check
echo -e "    ck_assert_double_eq_tol(isnan(tan(NAN)), isnan(s21_tan(NAN)), 1e-06);\n" >> atest.check
echo "#test tan_3_inf" >> atest.check
echo -e "    ck_assert_double_eq_tol(isinf(tan(INFINITY)), isinf(s21_tan(INFINITY)), 1e-06);\n" >> atest.check

checkmk clean_mode=1 atest.check > atest.c

rm -rf atest.check
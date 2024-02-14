#pragma once
#include <math.h>
#include "interpolation.h"

double calc_zero_rate(long num_term, double* term, double* rate, double fraction);
double calc_discount_factor(long num_term, double* term, double* rate, double fraction);
double calc_forward_rate(long num_term, double* term, double* rate, double fraction1, double fraction2);
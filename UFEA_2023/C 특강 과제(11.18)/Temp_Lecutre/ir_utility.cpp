#include "ir_utility.h"

double calc_zero_rate(long num_term, double* term, double* rate, double fraction)
{
    double result = 0.0;

    for (long i = 0; i < num_term; i++)
    {
        if (i == 0)
        {
            if (term[i] >= fraction)
            {
                result = rate[i];
                i = num_term;
            }
            else if (term[i] <= fraction && term[i + 1] >= fraction)
            {
                result = linear_interpolation(term[i], term[i + 1], rate[i], rate[i + 1], fraction);
                i = num_term;
            }
        }
        else if (i == num_term - 1) {
            if (term[i] <= fraction) {
                result = rate[i];
                i = num_term;
            }

        }
        else {
            if (term[i] <= fraction && term[i + 1] >= fraction)
            {
                result = linear_interpolation(term[i], term[i + 1], rate[i], rate[i + 1], fraction);
                i = num_term;
            }
        }
    }

    return result;
}

double calc_discount_factor(long num_term, double* term, double* rate, double fraction)
{
    return exp(-fraction * calc_zero_rate(num_term, term, rate, fraction));
}

double calc_forward_rate(long num_term, double* term, double* rate, double fraction1, double fraction2)
{
    double temp_forward_fraction = fraction2 - fraction1;

    return (calc_discount_factor(num_term, term, rate, fraction1)
        / calc_discount_factor(num_term, term, rate, fraction2) - 1.0)
        / temp_forward_fraction;
}
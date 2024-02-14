#include "TermStructure.h"

double termStructure::calc_zero_rate(double fraction)
{
    double result = 0.0;

    for (long i = 0; i < nTerm; i++)
    {
        if (i == 0)
        {
            if (*(term + i) >= fraction)
            {
                result = *(rate + i);
                i = nTerm;
            }
            else if (*(term + i) <= fraction && *(term + i + 1) >= fraction)
            {
                result = linear_interpolation(*(term + i), *(term + i + 1), *(rate + i), *(rate + i + 1), fraction);
                i = nTerm;
            }
        }
        else if (i == nTerm - 1) {
            if (*(term + i) <= fraction) {
                result = *(rate + i);
                i = nTerm;
            }

        }
        else {
            if (*(term + i) <= fraction && *(term + i + 1) >= fraction)
            {
                result = linear_interpolation(*(term + i), *(term + i + 1), *(rate + i), *(rate + i + 1), fraction);
                i = nTerm;
            }
        }
    }

    return result;
}

TermStructure* make_term_structure(const char* address)
{
	TermStructure* result = (TermStructure*)malloc(sizeof(TermStructure));
    if (!result) {
        return NULL;
    }
    char temp[10];
	result->nTerm = 1;
	result->term = (double*)malloc(sizeof(double) * result->nTerm);
	result->rate = (double*)malloc(sizeof(double) * result->nTerm);
	FILE* pFile = NULL;
	pFile = fopen(address, "r");
    result->nTerm = 0;

	if (pFile == NULL)
	{
		if (result) free(result);
        return NULL;
	}
	else
	{
		while (!feof(pFile)) {
            if (result->nTerm == 0) {
                fscanf(pFile, "%s, %s\n", temp, temp);
            }
            else {
                result->term = (double*)realloc(result->term, sizeof(double) * (result->nTerm + 1));
                result->rate = (double*)realloc(result->rate, sizeof(double) * (result->nTerm + 1));
                fscanf(pFile, "%lf, %lf\n",
                    result->term + result->nTerm - 1,
                    result->rate + result->nTerm - 1);
            }
			result->nTerm++;
		}
		result->nTerm--;
	}
	return result;
}

double discount_factor(TermStructure* term_structure, double fraction)
{
    return exp(-fraction * term_structure->calc_zero_rate(fraction));
}

double forward_rate(TermStructure* term_structure, double fraction1, double fraction2)
{
    return (exp(-fraction1 * term_structure->calc_zero_rate(fraction1))
        / exp(-fraction2 * term_structure->calc_zero_rate(fraction2)) - 1)/(fraction2 - fraction1);
}
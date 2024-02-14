#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"interpolation.h"

typedef struct termStructure {
	long nTerm;
	double* term;
	double* rate;

	double calc_zero_rate(double fraction);
} TermStructure;

TermStructure* make_term_structure(const char* address);

double discount_factor(TermStructure* term_structure, double fraction);
double forward_rate(TermStructure* term_structure, double fraction1, double fraction2);




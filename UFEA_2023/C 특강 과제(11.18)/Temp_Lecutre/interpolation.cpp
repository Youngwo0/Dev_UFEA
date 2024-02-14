#include "interpolation.h"

double linear_interpolation(double x1, double x2, double y1, double y2, double x)
{
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
}
#ifndef SRC_QUADRATIC_EQUATION_H
#define SRC_QUADRATIC_EQUATION_H
#include <math.h>
#include <stdio.h>

typedef struct {
  double x1;
  double x2;
  int num_roots;
} ResultQuEq;

ResultQuEq solve_equation(double a, double b, double c);

#endif  // SRC_QUADRATIC_EQUATION_H